void bye(void);
void qrx(void);
void txsto(void);
void next(void);
void dovar(void);
void docon(void);
void dolit(void);
void dolist(void);
void exitt(void);
void execu(void);
void donext(void);
void qbran(void);
void bran(void);
void store(void);
void at(void);
void cstor(void);
void cat(void);
void rfrom(void);
void rat(void);
void tor(void);
void drop(void);
void dup(void);
void swap(void);
void over(void);
void zless(void);
void andd(void);
void orr(void);
void xorr(void);
void uplus(void);
void nop(void);
void qdup(void);
void rot(void);
void ddrop(void);
void ddup(void);
void plus(void);
void inver(void);
void negat(void);
void dnega(void);
void subb(void);
void abss(void);
void great(void);
void less(void);
void equal(void);
void uless(void);
void ummod(void);
void msmod(void);
void slmod(void);
void mod(void);
void slash(void);
void umsta(void);
void star(void);
void mstar(void);
void ssmod(void);
void stasl(void);
void pick(void);
void pstor(void);
void dstor(void);
void dat(void);
void count(void);
void max_(void);
void min_(void);
//
/* Byte Code Assembler */
enum {
as_nop,   as_bye,    as_qrx,   as_txsto, as_docon, as_dolit, as_dolist, as_exit,
as_execu, as_donext, as_qbran, as_bran,  as_store, as_at,    as_cstor,  as_cat,
as_rpat,  as_rpsto,  as_rfrom, as_rat,   as_tor,   as_spat,  as_spsto,  as_drop,
as_dup,   as_swap,   as_over,  as_zless, as_andd,  as_orr,   as_xorr,   as_uplus,
as_next,  as_qdup,   as_rot,   as_ddrop, as_ddup,  as_plus,  as_inver,  as_negat,
as_dnega, as_subb,   as_abss,  as_equal, as_uless, as_less,  as_ummod,  as_msmod,
as_slmod, as_mod,    as_slash, as_umsta, as_star,  as_mstar, as_ssmod,  as_stasl,
as_pick,  as_pstor,  as_dstor, as_dat,   as_count, as_dovar, as_max,    as_min
} ByteCodes;
