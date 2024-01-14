vim.g.loaded_netrw = 1
vim.g.loaded_netrwPlugin = 1
vim.g.mapleader = " "
--vim.g.airline_theme = "onedark"
vim.opt.guioptions="a"
vim.opt.autochdir=true
vim.opt.smarttab=true
vim.opt.cindent=true
vim.opt.softtabstop=4
vim.opt.tabstop=4
vim.opt.wrap=true
vim.opt.shiftwidth=4
vim.opt.expandtab=true
vim.opt.ma=true
--vim.opt.mouse="a"
vim.opt.undofile=true
vim.opt.nu=true
vim.opt.linebreak=true
vim.opt.confirm=true
vim.opt.cmdheight=1
vim.opt.wildmenu=true
vim.opt.lazyredraw =true
vim.opt.incsearch=true
vim.opt.hlsearch=true
vim.opt.clipboard='unnamedplus'
vim.opt.splitbelow=true
vim.opt.cursorline=true
vim.opt.sidescroll=1
vim.opt.scrolloff=8
vim.opt.termguicolors=true

vim.cmd([[
set notimeout
set encoding=utf-8
set mouse+=a
let hlstate=0
nnoremap <silent><expr> <C-s> (&hls && v:hlsearch ? ':nohls' : ':set hls')."\n"
nnoremap \[ <Cmd>nohlsearch<Bar>diffupdate<Bar>normal <C-L><CR> 

vmap \\ <plug>NERDCommenterToggle
nmap \\ <plug>NERDCommenterToggle
]])


