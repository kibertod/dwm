
/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int gappx = 10;
static const unsigned int borderpx = 2; /* border pixel of windows */
static const unsigned int snap = 32; /* snap pixel */
static const int usealtbar = 1; /* 1 means use non-dwm status bar */
static const char* altbarclass = "Polybar"; /* Alternate bar class name */
static const char* altbarcmd =
    "bash -c \"/usr/bin/polybar -r bar &\""; /* Alternate bar launch command */
static const int showbar = 1; /* 0 means no bar */
static const int topbar = 1; /* 0 means bottom bar */
static const char* fonts[] = { "CommitMono Nerd Font Mono:size=10" };
static const char dmenufont[] = "CommitMono Nerd Font Mono:size=10";
static const char col_gray1[] = "#0f0f0f";
static const char col_gray2[] = "#444444";
static const char col_gray3[] = "#a5a9a5";
static const char col_gray4[] = "#c5c9c5";
static const char col_cyan[] = "#8ba4b0";
static const char* colors[][3] = {
    /*               fg         bg         border   */
    [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
    [SchemeSel] = { col_gray1,  col_cyan,  col_gray4 },
};

/* tagging */
static const char* tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     isfloating   monitor */
    {                                   "Firefox", NULL, NULL, 1 << 8, 0, -1 },
    {                              "Blueberry.py", NULL, NULL,      0, 1, -1 },
    {                                  "Nitrogen", NULL, NULL,      0, 1, -1 },
    {                              "Gnome-tweaks", NULL, NULL,      0, 1, -1 },
    {                      "Nm-connection-editor", NULL, NULL,      0, 1, -1 },
    { "ru-turikhay-tlauncher-bootstrap-Bootstrap", NULL, NULL,      0, 1, -1 },
    {                                 "Minecraft", NULL, NULL,      0, 1, -1 },
    {                               "File-roller", NULL, NULL,      0, 1, -1 },
    {                  "selectdefaultapplication", NULL, NULL,      0, 1, -1 },
    {                              "Image Lounge", NULL, NULL,      0, 1, -1 },
    {                               "pavucontrol", NULL, NULL,      0, 1, -1 },
    {                               "pwvucontrol", NULL, NULL,      0, 1, -1 },
    {                          "gnome-calculator", NULL, NULL,      0, 1, -1 },
    {                        "org.gnome.Nautilus", NULL, NULL,      0, 1, -1 },
    {                           "amplitube 5.exe", NULL, NULL,      0, 1, -1 },
};

/* layout(s) */
static const float mfact = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1; /* number of clients in master area */
static const int resizehints =
    1; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    1; /* 1 will force focus on the fullscreen window */

#include "fibonacci.c"
static const Layout layouts[] = {
    /* symbol     arrange function */
    {  "[]=",    tile }, /* first entry is default */
    {  "><>",    NULL },
    {  "[M]", monocle },
    { "[\\]", dwindle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG) \
    { MODKEY, KEY, view, { .ui = 1 << TAG } }, \
        { MODKEY | ControlMask, KEY, toggleview, { .ui = 1 << TAG } }, \
        { MODKEY | ShiftMask, KEY, tag, { .ui = 1 << TAG } }, \
        { MODKEY | ControlMask | ShiftMask, KEY, toggletag, \
            { .ui = 1 << TAG } },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) \
    { \
        .v = (const char*[]) { "/bin/sh", "-c", cmd, NULL } \
    }

/* commands */
static char dmenumon[2] = "0";
static const char* dmenucmd[] = { "rofi", "-show", "drun" };
static const char* termcmd[] = { "kitty", NULL };
static const char* filescmd[] = { "pcmanfm", NULL };
static const char* lockcmd[] = { "bash", "-c",
    "XSECURELOCK_DISCARD_FIRST_KEYPRESS=0 XSECURELOCK_COMPOSITE_OBSCURER=0 "
    "xsecurelock" };

static const Key keys[] = {
    /* modifier                     key        function        argument */
    {             MODKEY,      XK_d,      spawn,    { .v = dmenucmd } },
    {             MODKEY,      XK_e,      spawn,    { .v = filescmd } },
    {             MODKEY, XK_Return,      spawn,     { .v = termcmd } },
    {             MODKEY,      XK_b,  togglebar,                { 0 } },
    {             MODKEY,      XK_j, focusstack,          { .i = +1 } },
    {             MODKEY,      XK_k, focusstack,          { .i = -1 } },
    {             MODKEY,      XK_i, incnmaster,          { .i = +1 } },
    {             MODKEY,      XK_o, incnmaster,          { .i = -1 } },
    { MODKEY | ShiftMask,      XK_j,   setmfact,       { .f = -0.05 } },
    { MODKEY | ShiftMask,      XK_k,   setmfact,       { .f = +0.05 } },
    { MODKEY | ShiftMask, XK_Return,       zoom,                { 0 } },
    {             MODKEY,    XK_Tab,       view,                { 0 } },
    { MODKEY | ShiftMask,      XK_q, killclient,                { 0 } },
    {             MODKEY,      XK_t,  setlayout, { .v = &layouts[0] } },
    {             MODKEY,      XK_f,  setlayout, { .v = &layouts[1] } },
    {             MODKEY,      XK_m,  setlayout, { .v = &layouts[2] } },
    {             MODKEY,      XK_s,  setlayout, { .v = &layouts[3] } },
    {             MODKEY,      XK_l,      spawn,     { .v = lockcmd } },
    { MODKEY | ShiftMask,      XK_l,  setlayout,                { 0 } },
    {             MODKEY,      XK_0,       view,         { .ui = ~0 } },
    { MODKEY | ShiftMask,      XK_0,        tag,         { .ui = ~0 } },
    {             MODKEY,  XK_comma,   focusmon,          { .i = -1 } },
    {             MODKEY, XK_period,   focusmon,          { .i = +1 } },
    { MODKEY | ShiftMask,  XK_comma,     tagmon,          { .i = -1 } },
    { MODKEY | ShiftMask, XK_period,     tagmon,          { .i = +1 } },
    { MODKEY | ShiftMask,      XK_c,       quit,                { 0 } },
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function argument */
    {   ClkLtSymbol,      0, Button1,      setlayout,                { 0 } },
    {   ClkLtSymbol,      0, Button3,      setlayout, { .v = &layouts[2] } },
    {   ClkWinTitle,      0, Button2,           zoom,                { 0 } },
    { ClkStatusText,      0, Button2,          spawn,     { .v = termcmd } },
    {  ClkClientWin, MODKEY, Button1,      movemouse,                { 0 } },
    {  ClkClientWin, MODKEY, Button2, togglefloating,                { 0 } },
    {  ClkClientWin, MODKEY, Button3,    resizemouse,                { 0 } },
    {     ClkTagBar,      0, Button1,           view,                { 0 } },
    {     ClkTagBar,      0, Button3,     toggleview,                { 0 } },
    {     ClkTagBar, MODKEY, Button1,            tag,                { 0 } },
    {     ClkTagBar, MODKEY, Button3,      toggletag,                { 0 } },
};

// autostarttags
static const char* browsercmd[] = { "firefox", NULL };
static const char* telegram[] = { "bash", "-c","QT_QPA_PLATFORMTHEME=gtk3 telegram-desktop", NULL };

/* last cmd must be NULL! */
Autostarttag autostarttaglist[] = {
    { .cmd = browsercmd, .tags = 1 << 1 },
    {   .cmd = telegram, .tags = 1 << 3 },
    {       .cmd = NULL,      .tags = 0 },
};
static const char* ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = { IPCCOMMAND(view, 1, { ARG_TYPE_UINT }),
    IPCCOMMAND(toggleview, 1, { ARG_TYPE_UINT }),
    IPCCOMMAND(tag, 1, { ARG_TYPE_UINT }),
    IPCCOMMAND(toggletag, 1, { ARG_TYPE_UINT }),
    IPCCOMMAND(tagmon, 1, { ARG_TYPE_UINT }),
    IPCCOMMAND(focusmon, 1, { ARG_TYPE_SINT }),
    IPCCOMMAND(focusstack, 1, { ARG_TYPE_SINT }),
    IPCCOMMAND(zoom, 1, { ARG_TYPE_NONE }),
    IPCCOMMAND(incnmaster, 1, { ARG_TYPE_SINT }),
    IPCCOMMAND(killclient, 1, { ARG_TYPE_SINT }),
    IPCCOMMAND(togglefloating, 1, { ARG_TYPE_NONE }),
    IPCCOMMAND(setmfact, 1, { ARG_TYPE_FLOAT }),
    IPCCOMMAND(setlayoutsafe, 1, { ARG_TYPE_PTR }),
    IPCCOMMAND(quit, 1, { ARG_TYPE_NONE }) };
