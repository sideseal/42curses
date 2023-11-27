" ========================================
"
"           _____                         
"    ___   ____(_)______ _________________
"   ___ | / /_  /__  __ `__ \_  ___/  ___/
" _____ |/ /_  / _  / / / / /  /   / /__  
" _(_)____/ /_/  /_/ /_/ /_//_/    \___/  
"
" Maintainer: sideseal
" Last Modified: 2023-01-13 11:47:33
" ========================================

autocmd VimEnter * so /usr/share/vim/vimrc

" 1. General setup
"set nocompatible
syntax on
set termguicolors
"darkblue, murphy, slate,
colorscheme blue
set number
set nuw=5
set relativenumber
set title
set cc=80
set showtabline=2
set laststatus=2
" statusline settings >_<
" --------------------------------------------
set statusline=
set statusline +=\ %n\ 		"buffer number
set statusline +=%{&ff}		"file format
set statusline +=%y		"file type
set statusline +=\ %<%F		"full path
set statusline +=%m		"modified flag
set statusline +=%=%5l		"current line
set statusline +=/%L		"total lines
set statusline +=%4v\ 		"virtual column number
set statusline +=0x%04B\ 	"character under cursorset showcmd
" hi Statusline ctermbg=lightgreen ctermfg=black
" --------------------------------------------
set wildmenu
set wildmode=longest,list
set ruler
set showcmd
set nobackup
set noswapfile
set noerrorbells visualbell t_vb=
set vb
set mouse+=a
set noimd
set splitright
set splitbelow
" set backspace=indent,eol,start
" set hidden
set history=1000

set ve+=onemore
noremap $ $l

set wrap
set linebreak
" set breakindentopt=shift:2,min:40,sbr
set showbreak=↳
set breakindent

set clipboard=unnamed
nnoremap y "*y
nnoremap p "*p
nnoremap Y y$
nnoremap P p$
set timeout timeoutlen=200

augroup markdown
	autocmd!
	autocmd BufRead,BufNew *.md setf markdown
augroup END
set nofoldenable

"set hlsearch
"set incsearch
"set showmatch

" hi MatchParen ctermbg=lightgreen ctermfg=black

"set ignorecase
"set smartcase
set nows
nnoremap <ESC><ESC> :noh<return>

" filetype indent plugin on
set autoindent
set smartindent
" set cindent
set smarttab
set tabstop=4
set shiftwidth=4
" set noexpandtab
set fileencodings=utf-8,euc-kr
set fencs=ucs-bom,utf-8,euc-kr
set guifont=D2Coding:h12:cHANGEUL:qDEFAULT
set guifont=D2Coding:h12:cANSI:qDEFAULT
set guifontwide=D2Coding:h14
set list
" set listchars=tab:•·,trail:─,space:␣,eol:$
set listchars=tab:•·,trail:─
hi NonText ctermfg=darkgrey guifg=grey70
hi SpecialKey ctermfg=darkgrey guifg=grey70


nnoremap k gk
nnoremap j gj
nnoremap <UP>	gk
nnoremap <DOWN>	gj

set cursorline
set cursorlineopt=number
hi CursorLineNr cterm=bold

autocmd VimLeave * let &t_me="\<Esc>]50;CursorShape=1\x7"
let &t_SI.="\e[5 q" "SI = INSERT mode
let &t_SR.="\e[4 q" "SR = REPLACE mode
let &t_EI.="\e[5 q" "EI = NORMAL mode (ELSE)
set ttimeout
set ttimeoutlen=1
" set ttyfast


" 2. Personal settings

" command TT :vsplit output.txt | :split input.txt | :vertical resize 40<CR>
" nnoremap cc :execute '!make; ./app.out < input.txt > output.txt'<CR>
" nnoremap pp :execute '!python main.py < input.txt > output.txt'<CR>

nnoremap HH :Stdheader<CR>

set autoread
au CursorHold * checktime

let mapleader = "g"
noremap <leader>1 1gt
noremap <leader>2 2gt
noremap <leader>3 3gt
noremap <leader>4 4gt
noremap <leader>5 5gt
noremap <leader>6 6gt
noremap <leader>7 7gt
noremap <leader>8 8gt
noremap <leader>9 9gt
noremap <leader>h :tabmove -1<CR>
nnoremap <leader>l :tabmove +1<CR>
noremap <leader>0 :tablast<CR>

" let mapleader = "w"
" nmap <leader>h :vertical resize -5<CR>
" nmap <leader>l :vertical resize +5<CR>
" nmap <leader>k :resize +5<CR>
" nmap <leader>j :resize -5<CR>

" netwr setting moves like NERDTree!
" --------------------------------------------
let g:netrw_sort_sequence = '[\/]$,*'
let g:netrw_banner = 0
let g:netrw_liststyle = 3
let g:netrw_browse_split = 3
let g:netrw_alto = 1
let g:netrw_altv = 1
let g:netrw_winsize = 20
let g:netrw_fastbrowse = 0
let g:netrw_special_syntax = 1
nnoremap <silent> <TAB><TAB> : Vexplore %:p:h<CR>
autocmd FileType netrw nnoremap <buffer> <silent> <TAB><TAB> :bd<CR>

autocmd filetype netrw call Netrw_mappings()
function! Netrw_mappings()
	noremap <buffer>% :call CreateInPreview()<CR>
endfunction
function! CreateInPreview()
	let l:filename = input("please enter filename: ")
	execute 'silent !touch ' . b:netrw_curdir.'/'.l:filename 
	redraw!
endf
autocmd FileType netrw setl bufhidden=wipe
function! CloseNetrw() abort
  for bufn in range(1, bufnr('$'))
    if bufexists(bufn) && getbufvar(bufn, '&filetype') ==# 'netrw'
      silent! execute 'bwipeout ' . bufn
      if getline(2) =~# '^" Netrw '
        silent! bwipeout
      endif
      return
    endif
  endfor
endfunction
augroup closeOnOpen
  autocmd!
  autocmd BufWinEnter * if getbufvar(winbufnr(winnr()), "&filetype") != "netrw"|call CloseNetrw()|endif
aug END
" --------------------------------------------

if has('persistent_undo')
    let s:vimDir = '$HOME/.vim'
    let &runtimepath.=','.s:vimDir
    let s:undoDir = expand(s:vimDir . '/undodir')

    call system('mkdir ' . s:vimDir)
    call system('mkdir ' . s:undoDir)

    let &undodir = s:undoDir
    set undofile
endif
set undolevels=1000

" ---------------------------------------------

let g:markdown_fenced_languages = ['html', 'python', 'c', 'js=javascript', 'sh=bash', 'zsh', 'css', 'xml']
hi link markdownItalic Normal
hi link markdownError Normal
set maxmempattern=5000

autocmd BufWritePre ~/.vimrc :1,10s/^\" Last Modified: \zs.*$/\=strftime('%Y-%m-%d %H:%M:%S')/

" go to library functions
" gf & ctrl-O
"set path+=/usr/local/include/**2
"set path+=/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/**2
"set path+=/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/12.0.0/include/**2
"set path+=/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include/**2
"set path+=/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/**2
"set path+=/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/System/Library/Frameworks/**2

" Update path with the preprocessor's #include search paths. The C search
" paths are a subset of the C++ search paths, so they don't have to be
" additionally included.
"
" if has('unix') && executable('gcc')
"   let s:expr = 'gcc -Wp,-v -x c++ - -fsyntax-only 2>&1 </dev/null'
"   let s:lines = systemlist(s:expr)
"   if v:shell_error ==# 0
"     for s:line in s:lines
"       if match(s:line, '^ ') ==# -1 | continue | endif
"       let s:include = substitute(s:line, '^ ', '', '')
"       " Remove ' (framework directory)' suffix (applicable on macOS).
"       if match(s:include, ' (framework directory)$') && !isdirectory(s:include)
"         let s:include = substitute(s:include, ' (framework directory)$', '', '')
"       endif
"       if !isdirectory(s:include) | continue | endif
"       " Escape the path, including additional handling for spaces and commas.
"       let s:include = fnameescape(s:include)
"       let s:include = substitute(s:include, ',', '\\\\,', 'g')
"       let s:include = substitute(s:include, '\ ', '\\\\ ', 'g')
"       execute 'set path+=' . s:include
"     endfor
"   endif
" endif

function! CreateCenteredComment(comment)
	" Check if the comment fits within an 80-character comment.
	if len(a:comment) >= 74
		echoerr "Error: Comment is too long"
		return
	endif

	" Save the current line number of the cursor.
	let current_line = line('.')

	" Calculate the number of spaces on each side.
	let spaces_on_each_side = (74 - len(a:comment)) / 2

	" If length of comment is even, distribute them equally.
	" If it's odd, add one more space to the right side.
	let left_spaces = spaces_on_each_side
	let right_spaces = spaces_on_each_side + (len(a:comment) % 2)

	" The input comment to be inserted into the comment block.
	let inner_comment = '/* ' . repeat(' ', left_spaces) . a:comment .
						\ repeat(' ', right_spaces) . ' */'

	" The beginning part of the comment block.
	let start_comment = '/* ' . repeat('*', 74) . ' */'

	" The ending part of the comment block.
	let end_comment = '/* ' . repeat('*', 74) . ' */'

	" Make the completed comment block at the current cursor position.
	call append(current_line, [start_comment, inner_comment, end_comment])

	" Move the cursor down below the comment block and add an empty line.
	call append(current_line + 3, [''])

	" Move the cursor down.
	call cursor(current_line + 4, 1)
endfunction

" Set up a mapping to call the function.
nnoremap CC :call CreateCenteredComment(input('Enter comment: '))<CR>

" 0. Tips to remember
" 10^w< 	-> decrease buffer size (vertically)
" 10^w>		-> increase buffer size (vertically)
" 10^w+		-> increase buffer size (horizontally)
" 10^w-		-> decrease buffer size (horizontally)
" ^w=		-> equal buffer size
