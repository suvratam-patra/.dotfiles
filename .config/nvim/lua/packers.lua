-- This file can be loaded by calling `lua require('plugins')` from your init.vim

-- Only required if you have packer configured as `opt`
vim.cmd[[colorscheme dracula]]

return require('packer').startup(function(use)
  -- Packer can manage itself
  use 'wbthomason/packer.nvim'
  use 'Mofiqul/dracula.nvim'
  use {
	  'nvim-telescope/telescope.nvim', tag = '0.1.4',
	  --or                            , branch = '0.1.x',
	  requires = { {'nvim-lua/plenary.nvim'} }
  }
  use ('nvim-treesitter/nvim-treesitter', {run = ':TSUpdate'})
  use ('nvim-treesitter/playground')
  --  use {'neoclide/coc.nvim', branch = 'release'}
  use {
	  'nvim-lualine/lualine.nvim',
	  --requires = {{'nvim-tree/nvim-web-devicons', opt = true}}
  }
  use 'nvim-tree/nvim-web-devicons'
  use 'ryanoasis/vim-devicons'
  use 'neovim/nvim-lspconfig' -- Configurations for Nvim LSP
  --use {'romgrk/barbar.nvim', requires = 'nvim-web-devicons'}
  use {
	  'VonHeikemen/lsp-zero.nvim',
	  branch = 'v2.x',
	  requires = {
		  -- LSP Support
		  {'neovim/nvim-lspconfig'},             -- Required
		  {'williamboman/mason.nvim'},
		  {'williamboman/mason-lspconfig.nvim'}, -- Optional

		  -- Autocompletion
		  {'hrsh7th/nvim-cmp'},     -- Required
		  {'hrsh7th/cmp-nvim-lsp'}, -- Required
		  {'L3MON4D3/LuaSnip'},     -- Required
       }
  }
  use { 'hrsh7th/vim-vsnip' }
  use {'hrsh7th/vim-vsnip-integ' }
  use {'lukas-reineke/indent-blankline.nvim' }
  use {
	  "windwp/nvim-autopairs",
	  config = function() require("nvim-autopairs").setup {} end
  }
  use {
      'nvim-tree/nvim-tree.lua',
      requires = {
          --'nvim-tree/nvim-web-devicons', -- optional
      },
      config = function()
          require("nvim-tree").setup {}
      end
  }
  use {
      'filipdutescu/renamer.nvim',
      branch = 'master',
      requires = { {'nvim-lua/plenary.nvim'} }
  }
  use {'preservim/nerdcommenter'  }
  use {'dense-analysis/ale'}
  use {
       'akinsho/bufferline.nvim', 
        tag = "v3.*", 
        requires = 'nvim-tree/nvim-web-devicons'
      }
  use {"norcalli/nvim-colorizer.lua",}
end)



