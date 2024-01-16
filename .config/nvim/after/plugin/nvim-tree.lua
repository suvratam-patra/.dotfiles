-- examples for your init.lua

-- disable netrw at the very start of your init.lua (strongly advised)
--vim.g.loaded_netrw = 1
--vim.g.loaded_netrwPlugin = 1

-- set termguicolors to enable highlight groups
vim.opt.termguicolors = true
-- OR setup with some options
require("nvim-tree").setup({
    sort_by = "name",
    sync_root_with_cwd = true,
    respect_buf_cwd = true,
    renderer = {
          group_empty = false,
          highlight_opened_files = 'name',
        },
        filters = {
            dotfiles = false,
        },
        update_focused_file = {
            enable = true,
            update_cwd = true,
            update_root = true,
        },
        view = {
            centralize_selection = true,
            cursorline = true,
            debounce_delay = 50,
            width = 25,
            --hide_root_folder = false,
            side = "left",
            preserve_window_proportions = true,
            number = false,
            relativenumber = false,
            signcolumn = "yes",
        },
    })

