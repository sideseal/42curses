### ---- PATH -----------------------------------------------
export PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/munki:/Library/Apple/usr/bin:$HOME/misc/local/bin:$PATH

### ---- ZSH HOME -------------------------------------------
export ZSH=$HOME/Documents/42/42curses/.dotfiles/zsh

### ---- history config -------------------------------------
export HISTFILE=$ZSH/.zsh_history

## How many commands zsh will load to memory.
export HISTSIZE=10000

## How many commands history will save on file.
export SAVEHIST=10000

## History won't save duplicates.
setopt HIST_IGNORE_ALL_DUPS

## History won't show duplicates on search.
setopt HIST_FIND_NO_DUPS

### ---- PLUGINS --------------------------------------------
#source $ZSH/plugins/fast-syntax-highlighting/fast-syntax-highlighting.plugin.zsh
source $ZSH/plugins/zsh-autosuggestions/zsh-autosuggestions.zsh
fpath=($ZSH/plugins/zsh-completions/src $fpath)

### --- PLUGIN SETTINGS ------------------------------------

## ZSH-COMPLETIONS
autoload -Uz compinit && compinit -d $HOME/.cache/zsh/zcompdump-$ZSH_VERSION
zstyle ':completion:*' matcher-list '' 'm:{a-zA-Z}={A-Za-z}'

### ---- SETTINGS -------------------------------------------

## Alias
alias inception="~/misc/utils/vnc/inception"
alias rld="exec zsh"

## 42 Configuration
export USER="gychoi"
export MAIL="gychoi@student.42seoul.kr"

## Welcome message
echo "Hello, gychoi! ^_^\n"

# Customize prompt based on git status
source $ZSH/plugins/git-prompt.zsh/git-prompt.zsh
