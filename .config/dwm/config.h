/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const char panel[][20]       = { "xfce4-panel", "Xfce4-panel" }; /* name & cls of panel win */
static const unsigned int gappx     = 3;        /* gaps between windows */
static const unsigned int systraypinning = 1;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft =  0;
static const unsigned int systrayspacing = 3;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 0;     /* 0 means no systray */
static const unsigned int gappih    = 15;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 15;       /* vert inner gap between windows */
static const unsigned int gappoh    = 15;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 15;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 1;  
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char buttonbar[]       = " ";
static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */
static const Bool viewontag         = True;     /* Switch view on tag switch */

static const char *fonts[]          = {
                                  "ComicShannsMono Nerd Font:pixelsize=14:antialias=true:autohint=true",
                                  "JetBrainsMono Nerd Font:pixelsize=14:antialias=true:autohint=true",
                                  //"Feather:pixelsize=7:antialias=true:autohint=true", 
                                  //"FontAwesome:pixelsize=14:antialias=true:autohint=true", 
};

static const char dmenufont[]       = {"ComicShannsMono Nerd Font:size=10"};

static const char col_1[]  = "#12151f"; /* background color of bar */
static const char col_2[]  = "#fc8c03"; /* border color unfocused windows */
static const char col_3[]  = "#ffffff";
static const char col_4[]  = "#c0045c"; /* border color focused windows and tags */
static const char col_5[]  = "#2a3042"; /* border color focused windows and tags */
static const char col_6[]  = "#00b3ff";

static const unsigned int baralpha = 0xA1;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_3, col_1, col_1 },
	[SchemeSel]  = { col_6, col_5,  col_6  },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
//static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
/* static const char *tags[] = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" }; */
static const char *tags[] = {" ", " ", " ", " ", " ", " ", " ", " ", " ", " "};
/* static const char *tags[] = { "Web", "Chat", "Edit", "Meld", "Vb", "Mail", "Video", "Image", "Files" }; */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *  use tags mask to point an application to a specific workspace
	 */
	/* class                       instance    title      tags mask      isfloating   monitor */
	{ panel[1],                    NULL,       NULL,       (1 << 9) - 1, 1,           -1 },
    { "Gimp",                      NULL,       NULL,       0,            0,           -1 },
	{ "Blueman-manager",           NULL,       NULL,       0,            1,           -1 },
	{ "Pavucontrol",               NULL,       NULL,       0,            1,           -1 },
	{ "firefox",                   NULL,       NULL,       0,            0,           -1 },
	{ "VirtualBox Machine",        NULL,       NULL,       0,            1,           -1 },
	{ "Ld-linux-x86-64.so.2",      NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

//#include "layouts.c"

//static const Layout layouts[] = {
    //[> symbol     arrange function <]
    //{ "[]=",      tile },    [> first entry is default <]
    //{ "HHH",      grid },
    //{ "[M]",      monocle },
    //{ "><>",      NULL },    [> no layout function means floating behavior <]
    //{ NULL,       NULL },
//};

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	//{ "[@]",      spiral },
	//{ "[\\]",     dwindle },
	//{ "H[]",      deck },
	//{ "TTT",      bstack },
	//{ "===",      bstackhoriz },
	//{ "HHH",      grid },
	//{ "###",      nrowgrid },
	//{ "---",      horizgrid },
	//{ ":::",      gaplessgrid },
	//{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define CMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]    = { "dmenu_run", "-g", "10", "-l", "48", "-p", "Run: ", NULL };
static const char *filecmd[]     = { "pcmanfm", NULL };
static const char *launcher[]     = { "/home/suvratam/.config/dwm/launcher/launcher.sh", NULL };
/* the st terminal with tabbed */
static const char *termcmd[]     = { "alacritty", NULL };
static const char *taskmanager[]  = { "gnome-system-monitor", NULL };
static const char *calendar[]  = { "gsimplecal", NULL };
//static const char *bookmark[]    = { "/home/suvratam/.config/dwm/BookmarkList", NULL };
static const char *inc_bright[]    = { "/home/suvratam/.config/dwm/scripts/bright", "+", NULL };
static const char *drec_bright[]    = { "/home/suvratam/.config/dwm/scripts/bright", "-", NULL };
static const char *screenshot[]    = { "/home/suvratam/.config/dwm/scripts/scrot.sh", NULL};

#include "selfrestart.c"
#include "shiftview.c"

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_e,      spawn,          {.v = filecmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
    { 0,                            XK_Print,  spawn,          {.v = screenshot } },
    { MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_Right,  focusstack,     {.i = +1 } },
    { MODKEY,                       XK_Left,   focusstack,     {.i = -1 } },
    { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_o,      incnmaster,     {.i = -1 } },
	
    { MODKEY|ShiftMask,             XK_Down,   setcfact,       {.f = +0.15 } },
	{ MODKEY|ShiftMask,             XK_Up,     setcfact,       {.f = -0.15 } },
    { MODKEY|ShiftMask,             XK_Left,   setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_Right,  setmfact,       {.f = +0.05} },
    
    { MODKEY,                       XK_Return, zoom,           {0} },
	/*{ MODKEY,                       XK_Tab,    view,           {0} },*/
	{ MODKEY,						XK_q,      killclient,     {0} },

	{ MODKEY|Mod4Mask,              XK_minus,  incrgaps,       {.i = +2.5 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_minus,  incrgaps,       {.i = -2.5 } },
	{ MODKEY|Mod4Mask,              XK_equal,  incrigaps,      {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_equal,  incrigaps,      {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_o,      incrogaps,      {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_6,      incrihgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_7,      incrivgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_8,      incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_9,      incrovgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },

    { MODKEY|ControlMask,			XK_comma,  cyclelayout,    {.i = -1 } },
	{ MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
	{ MODKEY,                       XK_space,  cyclelayout,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_Left,   tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Right,  tagmon,         {.i = +1 } },

	{ MODKEY|ShiftMask,             XK_j,      rotatestack,    {.i = +1} },
	{ MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1} },
	{ MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.01} },
 	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },

    { Mod1Mask|ControlMask,         XK_Right,  shiftview,      {.i =  1 } },
	{ Mod1Mask|ControlMask,         XK_Left,   shiftview,      {.i = -1 } },
	{ Mod1Mask|ControlMask,         XK_Up,     shiftview,      {.i =  1 } },
	{ Mod1Mask|ControlMask,         XK_Down,   shiftview,      {.i = -1 } },	
	{ Mod1Mask,						XK_Tab,    shiftview,      {.i =  1 } },
	{ Mod1Mask|ShiftMask,	        XK_Tab,	   shiftview,	   {.i = -1 } },
	{ MODKEY,		        		XK_Tab,    shiftview,	   {.i =  1 } },
	{ MODKEY|ShiftMask,		        XK_Tab,	   shiftview,	   {.i = -1 } },
    { MODKEY,                       XK_h,      spawn,          SHCMD("xdotool type $(grep -v '^#' /home/suvratam/.local/share/bookmark | dmenu -i -l 50 | cut -d' ' -f1)") },
    { 0,                            XK_F3,     spawn,          {.v = inc_bright  } },
    { 0,                            XK_F2,     spawn,          {.v = drec_bright } },


	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
    
    /* Switch to specific layouts */
    { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[3]} },
	
    { MODKEY|ShiftMask,             XK_q,	  quit,		      {0} },
    { 0,                            XK_F1,     quit,           {1} },
    { MODKEY|ShiftMask,             XK_r,    self_restart,    {0} },
};

/* IF YOU HAVE A AZERTY KEYBOARD USE THESE CODES
	TAGKEYS(                        XK_ampersand,              0)
	TAGKEYS(                        XK_eacute,                 1)
	TAGKEYS(                        XK_quotedbl,               2)
	TAGKEYS(                        XK_apostrophe,             3)
	TAGKEYS(                        XK_parenleft,              4)
	TAGKEYS(                        XK_section,                5)
	TAGKEYS(                        XK_egrave,                 6)
	TAGKEYS(                        XK_exclam,                 7)
	TAGKEYS(                        XK_ccedilla,               8)
*/

/* THESE ARE THE ORIGINAL QWERTY KEYBOARD CODES
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
*/

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
    { ClkButton,		    0,  		    Button1,        spawn,  		{.v = launcher } },
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    //{ ClkTagBar,              0,              Button1,        tag,          {0} },
	//{ ClkTagBar,              0,              Button3,        toggletag,    {0} },
    { ClkStatusText,        0,              Button1,        spawn,          {.v = taskmanager } },
    { ClkStatusText,        0,              Button2,        spawn,          {.v = filecmd } },
    { ClkStatusText,        0,              Button3,        spawn,          {.v = calendar } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
