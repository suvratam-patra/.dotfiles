"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""               
"               
"               ██╗   ██╗██╗███╗   ███╗██████╗  ██████╗
"               ██║   ██║██║████╗ ████║██╔══██╗██╔════╝
"               ██║   ██║██║██╔████╔██║██████╔╝██║     
"               ╚██╗ ██╔╝██║██║╚██╔╝██║██╔══██╗██║     
"                ╚████╔╝ ██║██║ ╚═╝ ██║██║  ██║╚██████╗
"                 ╚═══╝  ╚═╝╚═╝     ╚═╝╚═╝  ╚═╝ ╚═════╝
"               
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""               
"KEY COMMAND FOLD/UNFOLD
"   zo---> to open a single fold under the cursor.
"   zc---> to close the fold under the cursor.
"   zR---> to open all folds.
"   zM---> to close all folds.

" SET VALUES -----------------------------------------------------------------{{{

set nocompatible
filetype off
filetype plugin on
filetype indent on

syntax on

set number
set cursorline
set shiftwidth=4
set tabstop=4
set expandtab
set nobackup
set scrolloff=10
set mouse=a
set clipboard=unnamed
set nowrap
set incsearch
set ignorecase
set smartcase
set showcmd
set showmode
set showmatch
set hlsearch
set history=1000
set wildmenu
set wildignore=*.docx,*.jpg,*.png,*.gif,*.pdf,*.pyc,*.exe,*.flv,*.img,*.xlsx
set autochdir
set smarttab
set cindent
set ma
set undodir=~/.vim/undodir
set undofile
set backspace=indent,eol,start
set linebreak
set nostartofline
set noswapfile
set confirm
set wildmenu
set lazyredraw 
set splitbelow
set sidescroll=1
set sidescrolloff=3
set encoding=UTF-8
" }}}

" PLUGINS ---------------------------------------------------------------- {{{

call plug#begin('~/.vim/plugged')
  Plug 'dense-analysis/ale'
  Plug 'preservim/nerdtree'
  Plug 'nvie/vim-togglemouse'
  Plug 'jistr/vim-nerdtree-tabs'
  Plug 'preservim/nerdcommenter'
  Plug 'xuyuanp/nerdtree-git-plugin'
  Plug 'vim-airline/vim-airline'
  Plug 'dracula/vim', { 'name': 'dracula'}
  "Plug 'neoclide/coc.nvim'
  "Plug 'neoclide/coc.nvim',{'do': 'yarn install --frozen-lockfile'}
  Plug 'joshdick/onedark.vim'
  Plug 'rafi/awesome-vim-colorschemes'
  Plug 'tiagofumo/vim-nerdtree-syntax-highlight'
  Plug 'ryanoasis/vim-devicons'
  Plug 'scrooloose/nerdtree'
  Plug 'natebosch/vim-lsc'
  Plug 'prabirshrestha/vim-lsp'
  Plug 'drewtempelmeyer/palenight.vim'
  Plug 'yggdroot/indentline'

call plug#end()
" }}}

" MAPPINGS --------------------------------------------------------------- {{{
let mapleader = " "
nnoremap <leader>\ ``
nnoremap <silent> <leader>p :%w !lp<CR>
"nnoremap <space> :
nnoremap o o<esc>
nnoremap O O<esc>
nnoremap n nzz
nnoremap N Nzz
nnoremap Y y$
nnoremap <c-a> ^
nnoremap <c-e> $
nnoremap <f5> :w <CR>:!clear <CR>:!python3 % <CR>
nnoremap <c-j> <c-w>j
nnoremap <c-k> <c-w>k
nnoremap <c-h> <c-w>h
nnoremap <c-l> <c-w>l
noremap <c-up> <c-w>+
noremap <c-down> <c-w>-
noremap <c-left> <c-w>>
noremap <c-right> <c-w><
nnoremap <c-n> :NERDTreeToggle<cr>
nnoremap \] :nohlsearch<cr>

vnoremap <C-c> :%w !xsel -i -b<CR><CR>

"let NERDTreeIgnore=['\.git$', '\.jpg$', '\.mp4$', '\.ogg$', '\.iso$', '\.pdf$', '\.pyc$', '\.odt$', '\.png$', '\.gif$', '\.db$']et g:lsc_auto_map = v:true
let g:lsc_auto_map = v:true
":set list lcs=tab:\|\

"COMMENT SINGLE LINE AND MULTILINE
vmap \\ <plug>NERDCommenterToggle
nmap \\ <plug>NERDCommenterToggle
" }}}

" VIMSCRIPT -------------------------------------------------------------- {{{

" Enable the marker method of folding.
augroup filetype_vim
    autocmd!
    autocmd FileType vim setlocal foldmethod=marker
augroup END

" If the current file type is HTML, set indentation to 2 spaces.
autocmd Filetype html setlocal tabstop=2 shiftwidth=2 expandtab
"TERMINAL COLOR ENHENCER

if (empty($TMUX))
  if (has("nvim"))
    let $NVIM_TUI_ENABLE_TRUE_COLOR=1
  endif
  if (has("termguicolors"))
    set termguicolors
  endif
endif

" If Vim version is equal to or greater than 7.3 enable undofile.
" This allows you to undo changes to a file even after saving it.
"if version >= 703
"    set undodir=~/.vim/backup
"    set undofile
"    set undoreload=10000
"endif

" You can split a window into sections by typing `:split` or `:vsplit`.
" Display cursorline and cursorcolumn ONLY in active window.
augroup cursor_off
    autocmd!
    autocmd WinLeave * set nocursorline nocursorcolumn
    autocmd WinEnter * set cursorline cursorcolumn
augroup END

    " Map the F4 key to toggle the menu, toolbar, and scroll bar.
    " <Bar> is the pipe character.
    " <CR> is the enter key.
    nnoremap <F4> :if &guioptions=~#'mTr'<Bar>
        \set guioptions-=mTr<Bar>
        \else<Bar>
        \set guioptions+=mTr<Bar>
        \endif<CR>
" }}}

" STATiUS LINE ------------------------------------------------------------ {{{
colorscheme dracula
"set background=dark
let g:airline_theme = "onedark"
" }}}

