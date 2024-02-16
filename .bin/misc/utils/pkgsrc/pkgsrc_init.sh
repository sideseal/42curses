#!/usr/bin/env zsh

# $1: command [/init/install/help]
# $2: package name

CMD=$1
PKG=$2
BUILD_PATH="$HOME/goinfre/pkgsrc"
INSTALL_PATH="$HOME/pkg"
CURRENT_PATH="$PWD"

init(){
	if [ ! -d $BUILD_PATH ]; then
		echo "install pkgsrc in goinfre"
		cd "$BUILD_PATH"
		curl -O http://ftp.netbsd.org/pub/pkgsrc/stable/pkgsrc.txz
		echo "unzip pkgsrc"
		tar -xzvf pkgsrc.txz
		echo "set pkgsrc env"
		OSX_SDK_PATH=$(xcrun -sdk macosx --show-sdk-path) ./bootstrap --unprivileged \
		&& echo 'OSX_SDK_PATH!=xcrun -sdk macosx -show-sdk-path' >> $HOME/pkg/etc/mk.conf \
		&& echo 'MAKE_JOBS!=sysctl -n hw.logicalcpu' >> $HOME/pkg/etc/mk.conf \
		&& echo 'export PATH=$HOME/pkg/sbin:$HOME/pkg/bin:$PATH' >> $HOME/.zshrc \
		&& echo 'export PATH=$HOME/pkg/bin:$PATH' >> $HOME/.zshrc \
		&& echo 'export MANPATH=$HOME/pkg/man:/usr/local/man:$MANPATH' >> $HOME/.zshrc \
		&& echo "alias pkgsrc=\"$CURRENT_PATH/pkgsrc_init.sh\"" >> $HOME/.zshrc \
		&& source $HOME/.zshrc
	else
		echo "pkgsrc is already installed"
		exit 1
	fi
}

install(){
	package=$1
	if [ ! -d $INSTALL_PATH ]; then
		echo "\'pkg\' directory not found. abort"
		exit 1
	else
		echo "finding package $package..."
		result=$(find $BUILD_PATH -name $package | wc -l)
		echo $result
		if (( $result > 0 )); then
			echo "find!"
			cd "$BUILD_PATH"
			bmake install $package
		else
			echo "cannot find package named $package"
			exit 1
		fi
	fi
}

help(){
	cat<<EOF

pkgsrc <command> [<package>]
command:

	help		: show usage
	init		: Install and initial setup for 42 environment
	install		: install package

EOF
}

if [[ $CMD == "init" ]]; then
	init
elif [[ $CMD == "install" ]]; then
	install $PKG
elif [[ $CMD == "help" ]]; then
	help
else
	help
fi

