
require("bufferline").setup{
    options = {
         offsets = {
            {
                filetype = "NvimTree",
                text="Nvim Tree",
                separator= true,
                text_align = "left"
            }
          },

          diagnostics_indicator = function(count, level, diagnostics_dict, context)
              local s = " "
              for e, n in pairs(diagnostics_dict) do
                  local sym = e == "error" and " "
                  or (e == "warning" and " " or "" )
                  s = s .. n .. sym
              end
              return s
          end;
          diagnostics = "nvim_lsp",
          separator_style = {"", ""},
          modified_icon = '●',
          show_close_icon = true,
          show_buffer_close_icons = true,
          indicator = {
            style = 'icon',
            icon = '▎',
            buffer_close_icon = ' ',
            modified_icon = '●',
            close_icon = ' ',
            left_trunc_marker = '',
            right_trunc_marker = '',
        },
    },
}
