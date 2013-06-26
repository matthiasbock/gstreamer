#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// adjustments to paths might be needed
#include <EGL/egl.h>
#include <EGL/eglplatform.h>
#include <GLES2/gl2.h>

static EGLint const attribute_list[] = {
    EGL_RED_SIZE, 1,
    EGL_GREEN_SIZE, 1,
    EGL_BLUE_SIZE, 1,
    EGL_NONE
};

static EGLint const context_attribute_list[] = {
    EGL_CONTEXT_CLIENT_VERSION, 2,
    EGL_NONE
};

struct gl_limit {
    GLint name;
    char *string;
    int num_args;
};
#define EXPAND(x) x, #x
struct gl_limit limits[] = {
    {EXPAND(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS), 1},
    {EXPAND(GL_MAX_CUBE_MAP_TEXTURE_SIZE), 1},
    {EXPAND(GL_MAX_FRAGMENT_UNIFORM_VECTORS), 1},
    {EXPAND(GL_MAX_RENDERBUFFER_SIZE), 1},
    {EXPAND(GL_MAX_TEXTURE_IMAGE_UNITS), 1},
    {EXPAND(GL_MAX_TEXTURE_SIZE), 1},
    {EXPAND(GL_MAX_VARYING_VECTORS), 1},
    {EXPAND(GL_MAX_VERTEX_ATTRIBS), 1},
    {EXPAND(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS), 1},
    {EXPAND(GL_MAX_VERTEX_UNIFORM_VECTORS), 1},
    {EXPAND(GL_MAX_VIEWPORT_DIMS), 2},
    {0, NULL}
};

int main(int argc, char ** argv)
{
    EGLDisplay display;
    EGLConfig config;
    EGLContext context;
    EGLSurface surface;
    EGLint num_config;

    // create a pbuffer-based surface, and use it
    display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    eglInitialize(display, NULL, NULL);
    eglChooseConfig(display, attribute_list, &config, 1, &num_config);
    context = eglCreateContext(display, config, EGL_NO_CONTEXT,
            context_attribute_list);
    surface = eglCreatePbufferSurface(display, config, NULL);
    eglMakeCurrent(display, surface, surface, context);

    // query egl-specific strings
    char *egl_vendor = (char *)eglQueryString(display, EGL_VENDOR);
    char *egl_version = (char *)eglQueryString(display, EGL_VERSION);
    char *egl_apis = (char *)eglQueryString(display, EGL_CLIENT_APIS);
    char *egl_exts = (char *)eglQueryString(display, EGL_EXTENSIONS);

    printf("EGL\n");
    printf("  Vendor: %s\n", egl_vendor);
    printf("  Version: %s\n", egl_version);
    printf("  Client APIs: %s\n", egl_apis);
    printf("  Extensions: %s\n", egl_exts);

    // query strings
    char *vendor = (char *)glGetString(GL_VENDOR);
    char *renderer = (char *)glGetString(GL_RENDERER);
    char *version = (char *)glGetString(GL_VERSION);
    char *glsl_version = (char *)glGetString(GL_SHADING_LANGUAGE_VERSION);
    char *exts = (char *)glGetString(GL_EXTENSIONS);

    printf("OpenGL ES\n");
    printf("  Vendor: %s\n", vendor);
    printf("  Renderer: %s\n", renderer);
    printf("  Version: %s\n", version);
    printf("  GLSL version: %s\n", glsl_version);
    printf("  Extensions: %s\n", exts);
    printf("  Implementation limits:\n");

    // query limits
    int i = 0;
    for (i = 0; limits[i].name != 0; i++) {
        int param[2] = {0, 0};
        glGetIntegerv(limits[i].name, param);
        if (limits[i].num_args == 1)
            printf("    %s = %d\n", limits[i].string, param[0]);
        else
            printf("    %s = %d, %d\n", limits[i].string, param[0], param[1]);

    }

    return EXIT_SUCCESS;
}
