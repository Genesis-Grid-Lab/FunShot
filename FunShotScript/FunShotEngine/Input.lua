-- define module table
local FunShotInput = {}

-- check mouse input
function FunShotInput.IsMouse(button)
    return ApiMouseDown(button)  
end

-- check key input
function FunShotInput.IsKey(key)
    return ApiKeyDown(key)
end

-- mouse input codes  
FunShotInput.MOUSE_LEFT     = 0
FunShotInput.MOUSE_MIDDLE   = 1
FunShotInput.MOUSE_RIGHT    = 2
FunShotInput.MOUSE_BUTTON_4 = 3
FunShotInput.MOUSE_BUTTON_5 = 4
FunShotInput.MOUSE_BUTTON_6 = 5
FunShotInput.MOUSE_BUTTON_7 = 6
FunShotInput.MOUSE_BUTTON_8 = 7

-- key input codes
FunShotInput.KEY_SPACE             = 32
FunShotInput.KEY_APOSTROPHE        = 39 
FunShotInput.KEY_COMMA             = 44 
FunShotInput.KEY_MINUS             = 45  
FunShotInput.KEY_PERIOD            = 46  
FunShotInput.KEY_SLASH             = 47  
FunShotInput.KEY_0                 = 48
FunShotInput.KEY_1                 = 49
FunShotInput.KEY_2                 = 50
FunShotInput.KEY_3                 = 51
FunShotInput.KEY_4                 = 52
FunShotInput.KEY_5                 = 53
FunShotInput.KEY_6                 = 54
FunShotInput.KEY_7                 = 55
FunShotInput.KEY_8                 = 56
FunShotInput.KEY_9                 = 57
FunShotInput.KEY_SEMICOLON         = 59  
FunShotInput.KEY_EQUAL             = 61  
FunShotInput.KEY_A                 = 65
FunShotInput.KEY_B                 = 66
FunShotInput.KEY_C                 = 67
FunShotInput.KEY_D                 = 68
FunShotInput.KEY_E                 = 69
FunShotInput.KEY_F                 = 70
FunShotInput.KEY_G                 = 71
FunShotInput.KEY_H                 = 72
FunShotInput.KEY_I                 = 73
FunShotInput.KEY_J                 = 74
FunShotInput.KEY_K                 = 75
FunShotInput.KEY_L                 = 76
FunShotInput.KEY_M                 = 77
FunShotInput.KEY_N                 = 78
FunShotInput.KEY_O                 = 79
FunShotInput.KEY_P                 = 80
FunShotInput.KEY_Q                 = 81
FunShotInput.KEY_R                 = 82
FunShotInput.KEY_S                 = 83
FunShotInput.KEY_T                 = 84
FunShotInput.KEY_U                 = 85
FunShotInput.KEY_V                 = 86
FunShotInput.KEY_W                 = 87
FunShotInput.KEY_X                 = 88
FunShotInput.KEY_Y                 = 89
FunShotInput.KEY_Z                 = 90
FunShotInput.KEY_LEFT_BRACKET      = 91   
FunShotInput.KEY_BACKSLASH         = 92   
FunShotInput.KEY_RIGHT_BRACKET     = 93   
FunShotInput.KEY_GRAVE_ACCENT      = 96   
FunShotInput.KEY_WORLD_1           = 161  
FunShotInput.KEY_WORLD_2           = 162  

-- Fion keys *--
FunShotInput.KEY_ESCAPE            = 256
FunShotInput.KEY_ENTER             = 257
FunShotInput.KEY_TAB               = 258
FunShotInput.KEY_BACKSPACE         = 259
FunShotInput.KEY_INSERT            = 260
FunShotInput.KEY_DELETE            = 261
FunShotInput.KEY_RIGHT             = 262
FunShotInput.KEY_LEFT              = 263
FunShotInput.KEY_DOWN              = 264
FunShotInput.KEY_UP                = 265
FunShotInput.KEY_PAGE_UP           = 266
FunShotInput.KEY_PAGE_DOWN         = 267
FunShotInput.KEY_HOME              = 268
FunShotInput.KEY_END               = 269
FunShotInput.KEY_CAPS_LOCK         = 280
FunShotInput.KEY_SCROLL_LOCK       = 281
FunShotInput.KEY_NUM_LOCK          = 282
FunShotInput.KEY_PRINT_SCREEN      = 283
FunShotInput.KEY_PAUSE             = 284
FunShotInput.KEY_F1                = 290
FunShotInput.KEY_F2                = 291
FunShotInput.KEY_F3                = 292
FunShotInput.KEY_F4                = 293
FunShotInput.KEY_F5                = 294
FunShotInput.KEY_F6                = 295
FunShotInput.KEY_F7                = 296
FunShotInput.KEY_F8                = 297
FunShotInput.KEY_F9                = 298
FunShotInput.KEY_F10               = 299
FunShotInput.KEY_F11               = 300
FunShotInput.KEY_F12               = 301
FunShotInput.KEY_F13               = 302
FunShotInput.KEY_F14               = 303
FunShotInput.KEY_F15               = 304
FunShotInput.KEY_F16               = 305
FunShotInput.KEY_F17               = 306
FunShotInput.KEY_F18               = 307
FunShotInput.KEY_F19               = 308
FunShotInput.KEY_F20               = 309
FunShotInput.KEY_F21               = 310
FunShotInput.KEY_F22               = 311
FunShotInput.KEY_F23               = 312
FunShotInput.KEY_F24               = 313
FunShotInput.KEY_F25               = 314
FunShotInput.KEY_KP_0              = 320
FunShotInput.KEY_KP_1              = 321
FunShotInput.KEY_KP_2              = 322
FunShotInput.KEY_KP_3              = 323
FunShotInput.KEY_KP_4              = 324
FunShotInput.KEY_KP_5              = 325
FunShotInput.KEY_KP_6              = 326
FunShotInput.KEY_KP_7              = 327
FunShotInput.KEY_KP_8              = 328
FunShotInput.KEY_KP_9              = 329
FunShotInput.KEY_KP_DECIMAL        = 330
FunShotInput.KEY_KP_DIVIDE         = 331
FunShotInput.KEY_KP_MULTIPLY       = 332
FunShotInput.KEY_KP_SUBTRACT       = 333
FunShotInput.KEY_KP_ADD            = 334
FunShotInput.KEY_KP_ENTER          = 335
FunShotInput.KEY_KP_EQUAL          = 336
FunShotInput.KEY_LEFT_SHIFT        = 340
FunShotInput.KEY_LEFT_CONTROL      = 341
FunShotInput.KEY_LEFT_ALT          = 342
FunShotInput.KEY_LEFT_SUPER        = 343
FunShotInput.KEY_RIGHT_SHIFT       = 344
FunShotInput.KEY_RIGHT_CONTROL     = 345
FunShotInput.KEY_RIGHT_ALT         = 346
FunShotInput.KEY_RIGHT_SUPER       = 347
FunShotInput.KEY_MENU              = 348

-- export module
return FunShotInput
