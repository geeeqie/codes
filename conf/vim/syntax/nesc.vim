" Install this file to ~/.vim/syntax/nesc.vim.

runtime! syntax/c.vim
let b:current_syntax = "nesc"

syn keyword     cStatement      abstract as async atomic call command
syn keyword     cStatement      components configuration event generic
syn keyword     cStatement      implementation includes interface module
syn keyword     cStatement      new norace post provides signal task unique
syn keyword     cStatement      uniqueCount uses

syn keyword     cType           result_t error_t nx_struct nx_uint8_t nx_uint16_t nx_uint32_t nx_int8_t nx_int16_t nx_int32_t nx_union

syn keyword     cConstant       SUCCESS FAIL TRUE FALSE

