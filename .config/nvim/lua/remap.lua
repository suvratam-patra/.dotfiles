vim.g.mapleader = " "
vim.api.nvim_command('filetype plugin indent on')
vim.keymap.set("n", "<C-b>", "<cmd>NvimTreeToggle<cr>")
vim.keymap.set("n", "<C-e>", "<cmd>e $PWD<cr>",{noremap = true, silent = true})
vim.api.nvim_set_keymap('v', '<C-c>', '"+y', { noremap = true, silent = true })
vim.api.nvim_set_keymap('v', '<C-x>', '"+ygv<DEL>', { noremap = true, silent = true })
