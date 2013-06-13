


#include "photography-enumtypes.h"

#include "photography.h"

/* enumerations from "photography.h" */
GType
gst_photography_noise_reduction_get_type (void)
{
  static volatile gsize g_define_type_id__volatile = 0;
  if (g_once_init_enter (&g_define_type_id__volatile)) {
    static const GFlagsValue values[] = {
      { GST_PHOTOGRAPHY_NOISE_REDUCTION_BAYER, "GST_PHOTOGRAPHY_NOISE_REDUCTION_BAYER", "bayer" },
      { GST_PHOTOGRAPHY_NOISE_REDUCTION_YCC, "GST_PHOTOGRAPHY_NOISE_REDUCTION_YCC", "ycc" },
      { GST_PHOTOGRAPHY_NOISE_REDUCTION_TEMPORAL, "GST_PHOTOGRAPHY_NOISE_REDUCTION_TEMPORAL", "temporal" },
      { GST_PHOTOGRAPHY_NOISE_REDUCTION_FIXED, "GST_PHOTOGRAPHY_NOISE_REDUCTION_FIXED", "fixed" },
      { GST_PHOTOGRAPHY_NOISE_REDUCTION_EXTRA, "GST_PHOTOGRAPHY_NOISE_REDUCTION_EXTRA", "extra" },
      { 0, NULL, NULL }
    };
    GType g_define_type_id = g_flags_register_static ("GstPhotographyNoiseReduction", values);
    g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
  }
  return g_define_type_id__volatile;
}
GType
gst_photography_white_balance_mode_get_type (void)
{
  static volatile gsize g_define_type_id__volatile = 0;
  if (g_once_init_enter (&g_define_type_id__volatile)) {
    static const GEnumValue values[] = {
      { GST_PHOTOGRAPHY_WB_MODE_AUTO, "GST_PHOTOGRAPHY_WB_MODE_AUTO", "auto" },
      { GST_PHOTOGRAPHY_WB_MODE_DAYLIGHT, "GST_PHOTOGRAPHY_WB_MODE_DAYLIGHT", "daylight" },
      { GST_PHOTOGRAPHY_WB_MODE_CLOUDY, "GST_PHOTOGRAPHY_WB_MODE_CLOUDY", "cloudy" },
      { GST_PHOTOGRAPHY_WB_MODE_SUNSET, "GST_PHOTOGRAPHY_WB_MODE_SUNSET", "sunset" },
      { GST_PHOTOGRAPHY_WB_MODE_TUNGSTEN, "GST_PHOTOGRAPHY_WB_MODE_TUNGSTEN", "tungsten" },
      { GST_PHOTOGRAPHY_WB_MODE_FLUORESCENT, "GST_PHOTOGRAPHY_WB_MODE_FLUORESCENT", "fluorescent" },
      { GST_PHOTOGRAPHY_WB_MODE_MANUAL, "GST_PHOTOGRAPHY_WB_MODE_MANUAL", "manual" },
      { GST_PHOTOGRAPHY_WB_MODE_WARM_FLUORESCENT, "GST_PHOTOGRAPHY_WB_MODE_WARM_FLUORESCENT", "warm-fluorescent" },
      { GST_PHOTOGRAPHY_WB_MODE_SHADE, "GST_PHOTOGRAPHY_WB_MODE_SHADE", "shade" },
      { 0, NULL, NULL }
    };
    GType g_define_type_id = g_enum_register_static ("GstPhotographyWhiteBalanceMode", values);
    g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
  }
  return g_define_type_id__volatile;
}
GType
gst_photography_color_tone_mode_get_type (void)
{
  static volatile gsize g_define_type_id__volatile = 0;
  if (g_once_init_enter (&g_define_type_id__volatile)) {
    static const GEnumValue values[] = {
      { GST_PHOTOGRAPHY_COLOR_TONE_MODE_NORMAL, "GST_PHOTOGRAPHY_COLOR_TONE_MODE_NORMAL", "normal" },
      { GST_PHOTOGRAPHY_COLOR_TONE_MODE_SEPIA, "GST_PHOTOGRAPHY_COLOR_TONE_MODE_SEPIA", "sepia" },
      { GST_PHOTOGRAPHY_COLOR_TONE_MODE_NEGATIVE, "GST_PHOTOGRAPHY_COLOR_TONE_MODE_NEGATIVE", "negative" },
      { GST_PHOTOGRAPHY_COLOR_TONE_MODE_GRAYSCALE, "GST_PHOTOGRAPHY_COLOR_TONE_MODE_GRAYSCALE", "grayscale" },
      { GST_PHOTOGRAPHY_COLOR_TONE_MODE_NATURAL, "GST_PHOTOGRAPHY_COLOR_TONE_MODE_NATURAL", "natural" },
      { GST_PHOTOGRAPHY_COLOR_TONE_MODE_VIVID, "GST_PHOTOGRAPHY_COLOR_TONE_MODE_VIVID", "vivid" },
      { GST_PHOTOGRAPHY_COLOR_TONE_MODE_COLORSWAP, "GST_PHOTOGRAPHY_COLOR_TONE_MODE_COLORSWAP", "colorswap" },
      { GST_PHOTOGRAPHY_COLOR_TONE_MODE_SOLARIZE, "GST_PHOTOGRAPHY_COLOR_TONE_MODE_SOLARIZE", "solarize" },
      { GST_PHOTOGRAPHY_COLOR_TONE_MODE_OUT_OF_FOCUS, "GST_PHOTOGRAPHY_COLOR_TONE_MODE_OUT_OF_FOCUS", "out-of-focus" },
      { GST_PHOTOGRAPHY_COLOR_TONE_MODE_SKY_BLUE, "GST_PHOTOGRAPHY_COLOR_TONE_MODE_SKY_BLUE", "sky-blue" },
      { GST_PHOTOGRAPHY_COLOR_TONE_MODE_GRASS_GREEN, "GST_PHOTOGRAPHY_COLOR_TONE_MODE_GRASS_GREEN", "grass-green" },
      { GST_PHOTOGRAPHY_COLOR_TONE_MODE_SKIN_WHITEN, "GST_PHOTOGRAPHY_COLOR_TONE_MODE_SKIN_WHITEN", "skin-whiten" },
      { GST_PHOTOGRAPHY_COLOR_TONE_MODE_POSTERIZE, "GST_PHOTOGRAPHY_COLOR_TONE_MODE_POSTERIZE", "posterize" },
      { GST_PHOTOGRAPHY_COLOR_TONE_MODE_WHITEBOARD, "GST_PHOTOGRAPHY_COLOR_TONE_MODE_WHITEBOARD", "whiteboard" },
      { GST_PHOTOGRAPHY_COLOR_TONE_MODE_BLACKBOARD, "GST_PHOTOGRAPHY_COLOR_TONE_MODE_BLACKBOARD", "blackboard" },
      { GST_PHOTOGRAPHY_COLOR_TONE_MODE_AQUA, "GST_PHOTOGRAPHY_COLOR_TONE_MODE_AQUA", "aqua" },
      { 0, NULL, NULL }
    };
    GType g_define_type_id = g_enum_register_static ("GstPhotographyColorToneMode", values);
    g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
  }
  return g_define_type_id__volatile;
}
GType
gst_photography_scene_mode_get_type (void)
{
  static volatile gsize g_define_type_id__volatile = 0;
  if (g_once_init_enter (&g_define_type_id__volatile)) {
    static const GEnumValue values[] = {
      { GST_PHOTOGRAPHY_SCENE_MODE_MANUAL, "GST_PHOTOGRAPHY_SCENE_MODE_MANUAL", "manual" },
      { GST_PHOTOGRAPHY_SCENE_MODE_CLOSEUP, "GST_PHOTOGRAPHY_SCENE_MODE_CLOSEUP", "closeup" },
      { GST_PHOTOGRAPHY_SCENE_MODE_PORTRAIT, "GST_PHOTOGRAPHY_SCENE_MODE_PORTRAIT", "portrait" },
      { GST_PHOTOGRAPHY_SCENE_MODE_LANDSCAPE, "GST_PHOTOGRAPHY_SCENE_MODE_LANDSCAPE", "landscape" },
      { GST_PHOTOGRAPHY_SCENE_MODE_SPORT, "GST_PHOTOGRAPHY_SCENE_MODE_SPORT", "sport" },
      { GST_PHOTOGRAPHY_SCENE_MODE_NIGHT, "GST_PHOTOGRAPHY_SCENE_MODE_NIGHT", "night" },
      { GST_PHOTOGRAPHY_SCENE_MODE_AUTO, "GST_PHOTOGRAPHY_SCENE_MODE_AUTO", "auto" },
      { GST_PHOTOGRAPHY_SCENE_MODE_ACTION, "GST_PHOTOGRAPHY_SCENE_MODE_ACTION", "action" },
      { GST_PHOTOGRAPHY_SCENE_MODE_NIGHT_PORTRAIT, "GST_PHOTOGRAPHY_SCENE_MODE_NIGHT_PORTRAIT", "night-portrait" },
      { GST_PHOTOGRAPHY_SCENE_MODE_THEATRE, "GST_PHOTOGRAPHY_SCENE_MODE_THEATRE", "theatre" },
      { GST_PHOTOGRAPHY_SCENE_MODE_BEACH, "GST_PHOTOGRAPHY_SCENE_MODE_BEACH", "beach" },
      { GST_PHOTOGRAPHY_SCENE_MODE_SNOW, "GST_PHOTOGRAPHY_SCENE_MODE_SNOW", "snow" },
      { GST_PHOTOGRAPHY_SCENE_MODE_SUNSET, "GST_PHOTOGRAPHY_SCENE_MODE_SUNSET", "sunset" },
      { GST_PHOTOGRAPHY_SCENE_MODE_STEADY_PHOTO, "GST_PHOTOGRAPHY_SCENE_MODE_STEADY_PHOTO", "steady-photo" },
      { GST_PHOTOGRAPHY_SCENE_MODE_FIREWORKS, "GST_PHOTOGRAPHY_SCENE_MODE_FIREWORKS", "fireworks" },
      { GST_PHOTOGRAPHY_SCENE_MODE_PARTY, "GST_PHOTOGRAPHY_SCENE_MODE_PARTY", "party" },
      { GST_PHOTOGRAPHY_SCENE_MODE_CANDLELIGHT, "GST_PHOTOGRAPHY_SCENE_MODE_CANDLELIGHT", "candlelight" },
      { GST_PHOTOGRAPHY_SCENE_MODE_BARCODE, "GST_PHOTOGRAPHY_SCENE_MODE_BARCODE", "barcode" },
      { 0, NULL, NULL }
    };
    GType g_define_type_id = g_enum_register_static ("GstPhotographySceneMode", values);
    g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
  }
  return g_define_type_id__volatile;
}
GType
gst_photography_flash_mode_get_type (void)
{
  static volatile gsize g_define_type_id__volatile = 0;
  if (g_once_init_enter (&g_define_type_id__volatile)) {
    static const GEnumValue values[] = {
      { GST_PHOTOGRAPHY_FLASH_MODE_AUTO, "GST_PHOTOGRAPHY_FLASH_MODE_AUTO", "auto" },
      { GST_PHOTOGRAPHY_FLASH_MODE_OFF, "GST_PHOTOGRAPHY_FLASH_MODE_OFF", "off" },
      { GST_PHOTOGRAPHY_FLASH_MODE_ON, "GST_PHOTOGRAPHY_FLASH_MODE_ON", "on" },
      { GST_PHOTOGRAPHY_FLASH_MODE_FILL_IN, "GST_PHOTOGRAPHY_FLASH_MODE_FILL_IN", "fill-in" },
      { GST_PHOTOGRAPHY_FLASH_MODE_RED_EYE, "GST_PHOTOGRAPHY_FLASH_MODE_RED_EYE", "red-eye" },
      { 0, NULL, NULL }
    };
    GType g_define_type_id = g_enum_register_static ("GstPhotographyFlashMode", values);
    g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
  }
  return g_define_type_id__volatile;
}
GType
gst_photography_focus_status_get_type (void)
{
  static volatile gsize g_define_type_id__volatile = 0;
  if (g_once_init_enter (&g_define_type_id__volatile)) {
    static const GEnumValue values[] = {
      { GST_PHOTOGRAPHY_FOCUS_STATUS_NONE, "GST_PHOTOGRAPHY_FOCUS_STATUS_NONE", "none" },
      { GST_PHOTOGRAPHY_FOCUS_STATUS_RUNNING, "GST_PHOTOGRAPHY_FOCUS_STATUS_RUNNING", "running" },
      { GST_PHOTOGRAPHY_FOCUS_STATUS_FAIL, "GST_PHOTOGRAPHY_FOCUS_STATUS_FAIL", "fail" },
      { GST_PHOTOGRAPHY_FOCUS_STATUS_SUCCESS, "GST_PHOTOGRAPHY_FOCUS_STATUS_SUCCESS", "success" },
      { 0, NULL, NULL }
    };
    GType g_define_type_id = g_enum_register_static ("GstPhotographyFocusStatus", values);
    g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
  }
  return g_define_type_id__volatile;
}
GType
gst_photography_caps_get_type (void)
{
  static volatile gsize g_define_type_id__volatile = 0;
  if (g_once_init_enter (&g_define_type_id__volatile)) {
    static const GFlagsValue values[] = {
      { GST_PHOTOGRAPHY_CAPS_NONE, "GST_PHOTOGRAPHY_CAPS_NONE", "none" },
      { GST_PHOTOGRAPHY_CAPS_EV_COMP, "GST_PHOTOGRAPHY_CAPS_EV_COMP", "ev-comp" },
      { GST_PHOTOGRAPHY_CAPS_ISO_SPEED, "GST_PHOTOGRAPHY_CAPS_ISO_SPEED", "iso-speed" },
      { GST_PHOTOGRAPHY_CAPS_WB_MODE, "GST_PHOTOGRAPHY_CAPS_WB_MODE", "wb-mode" },
      { GST_PHOTOGRAPHY_CAPS_TONE, "GST_PHOTOGRAPHY_CAPS_TONE", "tone" },
      { GST_PHOTOGRAPHY_CAPS_SCENE, "GST_PHOTOGRAPHY_CAPS_SCENE", "scene" },
      { GST_PHOTOGRAPHY_CAPS_FLASH, "GST_PHOTOGRAPHY_CAPS_FLASH", "flash" },
      { GST_PHOTOGRAPHY_CAPS_ZOOM, "GST_PHOTOGRAPHY_CAPS_ZOOM", "zoom" },
      { GST_PHOTOGRAPHY_CAPS_FOCUS, "GST_PHOTOGRAPHY_CAPS_FOCUS", "focus" },
      { GST_PHOTOGRAPHY_CAPS_APERTURE, "GST_PHOTOGRAPHY_CAPS_APERTURE", "aperture" },
      { GST_PHOTOGRAPHY_CAPS_EXPOSURE, "GST_PHOTOGRAPHY_CAPS_EXPOSURE", "exposure" },
      { GST_PHOTOGRAPHY_CAPS_SHAKE, "GST_PHOTOGRAPHY_CAPS_SHAKE", "shake" },
      { GST_PHOTOGRAPHY_CAPS_WHITE_BALANCE, "GST_PHOTOGRAPHY_CAPS_WHITE_BALANCE", "white-balance" },
      { GST_PHOTOGRAPHY_CAPS_NOISE_REDUCTION, "GST_PHOTOGRAPHY_CAPS_NOISE_REDUCTION", "noise-reduction" },
      { GST_PHOTOGRAPHY_CAPS_FLICKER_REDUCTION, "GST_PHOTOGRAPHY_CAPS_FLICKER_REDUCTION", "flicker-reduction" },
      { GST_PHOTOGRAPHY_CAPS_ALL, "GST_PHOTOGRAPHY_CAPS_ALL", "all" },
      { 0, NULL, NULL }
    };
    GType g_define_type_id = g_flags_register_static ("GstPhotographyCaps", values);
    g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
  }
  return g_define_type_id__volatile;
}
GType
gst_photography_shake_risk_get_type (void)
{
  static volatile gsize g_define_type_id__volatile = 0;
  if (g_once_init_enter (&g_define_type_id__volatile)) {
    static const GEnumValue values[] = {
      { GST_PHOTOGRAPHY_SHAKE_RISK_LOW, "GST_PHOTOGRAPHY_SHAKE_RISK_LOW", "low" },
      { GST_PHOTOGRAPHY_SHAKE_RISK_MEDIUM, "GST_PHOTOGRAPHY_SHAKE_RISK_MEDIUM", "medium" },
      { GST_PHOTOGRAPHY_SHAKE_RISK_HIGH, "GST_PHOTOGRAPHY_SHAKE_RISK_HIGH", "high" },
      { 0, NULL, NULL }
    };
    GType g_define_type_id = g_enum_register_static ("GstPhotographyShakeRisk", values);
    g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
  }
  return g_define_type_id__volatile;
}
GType
gst_photography_flicker_reduction_mode_get_type (void)
{
  static volatile gsize g_define_type_id__volatile = 0;
  if (g_once_init_enter (&g_define_type_id__volatile)) {
    static const GEnumValue values[] = {
      { GST_PHOTOGRAPHY_FLICKER_REDUCTION_OFF, "GST_PHOTOGRAPHY_FLICKER_REDUCTION_OFF", "off" },
      { GST_PHOTOGRAPHY_FLICKER_REDUCTION_50HZ, "GST_PHOTOGRAPHY_FLICKER_REDUCTION_50HZ", "50hz" },
      { GST_PHOTOGRAPHY_FLICKER_REDUCTION_60HZ, "GST_PHOTOGRAPHY_FLICKER_REDUCTION_60HZ", "60hz" },
      { GST_PHOTOGRAPHY_FLICKER_REDUCTION_AUTO, "GST_PHOTOGRAPHY_FLICKER_REDUCTION_AUTO", "auto" },
      { 0, NULL, NULL }
    };
    GType g_define_type_id = g_enum_register_static ("GstPhotographyFlickerReductionMode", values);
    g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
  }
  return g_define_type_id__volatile;
}
GType
gst_photography_focus_mode_get_type (void)
{
  static volatile gsize g_define_type_id__volatile = 0;
  if (g_once_init_enter (&g_define_type_id__volatile)) {
    static const GEnumValue values[] = {
      { GST_PHOTOGRAPHY_FOCUS_MODE_AUTO, "GST_PHOTOGRAPHY_FOCUS_MODE_AUTO", "auto" },
      { GST_PHOTOGRAPHY_FOCUS_MODE_MACRO, "GST_PHOTOGRAPHY_FOCUS_MODE_MACRO", "macro" },
      { GST_PHOTOGRAPHY_FOCUS_MODE_PORTRAIT, "GST_PHOTOGRAPHY_FOCUS_MODE_PORTRAIT", "portrait" },
      { GST_PHOTOGRAPHY_FOCUS_MODE_INFINITY, "GST_PHOTOGRAPHY_FOCUS_MODE_INFINITY", "infinity" },
      { GST_PHOTOGRAPHY_FOCUS_MODE_HYPERFOCAL, "GST_PHOTOGRAPHY_FOCUS_MODE_HYPERFOCAL", "hyperfocal" },
      { GST_PHOTOGRAPHY_FOCUS_MODE_EXTENDED, "GST_PHOTOGRAPHY_FOCUS_MODE_EXTENDED", "extended" },
      { GST_PHOTOGRAPHY_FOCUS_MODE_CONTINUOUS_NORMAL, "GST_PHOTOGRAPHY_FOCUS_MODE_CONTINUOUS_NORMAL", "continuous-normal" },
      { GST_PHOTOGRAPHY_FOCUS_MODE_CONTINUOUS_EXTENDED, "GST_PHOTOGRAPHY_FOCUS_MODE_CONTINUOUS_EXTENDED", "continuous-extended" },
      { GST_PHOTOGRAPHY_FOCUS_MODE_MANUAL, "GST_PHOTOGRAPHY_FOCUS_MODE_MANUAL", "manual" },
      { 0, NULL, NULL }
    };
    GType g_define_type_id = g_enum_register_static ("GstPhotographyFocusMode", values);
    g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
  }
  return g_define_type_id__volatile;
}
GType
gst_photography_exposure_mode_get_type (void)
{
  static volatile gsize g_define_type_id__volatile = 0;
  if (g_once_init_enter (&g_define_type_id__volatile)) {
    static const GEnumValue values[] = {
      { GST_PHOTOGRAPHY_EXPOSURE_MODE_AUTO, "GST_PHOTOGRAPHY_EXPOSURE_MODE_AUTO", "auto" },
      { GST_PHOTOGRAPHY_EXPOSURE_MODE_MANUAL, "GST_PHOTOGRAPHY_EXPOSURE_MODE_MANUAL", "manual" },
      { 0, NULL, NULL }
    };
    GType g_define_type_id = g_enum_register_static ("GstPhotographyExposureMode", values);
    g_once_init_leave (&g_define_type_id__volatile, g_define_type_id);
  }
  return g_define_type_id__volatile;
}



