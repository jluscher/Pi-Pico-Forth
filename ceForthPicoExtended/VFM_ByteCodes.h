#include "Utilities.h"
//
// Byte Code Assembler 
//
#ifndef EXTENSIONS
enum {
as_nop,   as_bye,    as_qrx,   as_txsto, as_docon, as_dolit,    as_dolist, as_exit,
as_execu, as_donext, as_qbran, as_bran,  as_store, as_at,       as_cstor,  as_cat,
as_rpat,  as_rpsto,  as_rfrom, as_rat,   as_tor,   as_spat,     as_spsto,  as_drop,
as_dup,   as_swap,   as_over,  as_zless, as_andd,  as_orr,      as_xorr,   as_uplus,
as_next,  as_qdup,   as_rot,   as_ddrop, as_ddup,  as_plus,     as_inver,  as_negat,
as_dnega, as_subb,   as_abss,  as_equal, as_uless, as_less,     as_ummod,  as_msmod,
as_slmod, as_mod,    as_slash, as_umsta, as_star,  as_mstar,    as_ssmod,  as_stasl,
as_pick,  as_pstor,  as_dstor, as_dat,   as_count, as_dovar,    as_max,    as_min
} ByteCodes;
#else
enum {
as_nop,   as_bye,    as_qrx,   as_txsto, as_docon, as_dolit,    as_dolist, as_exit,
as_execu, as_donext, as_qbran, as_bran,  as_store, as_at,       as_cstor,  as_cat,
as_rpat,  as_rpsto,  as_rfrom, as_rat,   as_tor,   as_spat,     as_spsto,  as_drop,
as_dup,   as_swap,   as_over,  as_zless, as_andd,  as_orr,      as_xorr,   as_uplus,
as_next,  as_qdup,   as_rot,   as_ddrop, as_ddup,  as_plus,     as_inver,  as_negat,
as_dnega, as_subb,   as_abss,  as_equal, as_uless, as_less,     as_ummod,  as_msmod,
as_slmod, as_mod,    as_slash, as_umsta, as_star,  as_mstar,    as_ssmod,  as_stasl,
as_pick,  as_pstor,  as_dstor, as_dat,   as_count, as_dovar,    as_max,    as_min,
 as_f_temp_on,
 as_f_temp_off,
 as_f_adc_init,
 as_f_adc_gpio_init,   
 as_f_adc_select_input, 
 as_f_adc_read,
 as_f_gpio_get_dir,
 as_f_gpio_get_drive_strength,
 as_f_gpio_get_slew_rate,
 as_f_gpio_disable_pulls,
 as_f_gpio_pull_up,
 as_f_gpio_pull_down,
 as_f_gpio_is_pulled_up,
 as_f_gpio_is_pulled_down,
 as_f_gpio_is_input_hysteresis_enabled,
 as_f_gpio_get, 
 as_f_gpio_init,
 as_f_gpio_set_dir,
 as_f_gpio_put,
 as_f_gpio_set_drive_strength,
 as_f_gpio_set_slew_rate,
 as_f_gpio_set_input_hysteresis_enabled,
 as_f_flash_sector_erase,               
 as_f_flash_store,                      
 as_f_flash_page_list,                  
 as_f_flash_get_unique_id,              
 as_f_page_pattern,                     
 as_f_WipeAllSectors                     
} ByteCodes;
#endif
