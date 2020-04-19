/* glkstart.h: Unix-specific header file for GlkTerm, CheapGlk, and XGlk
        (Unix implementations of the Glk API).
    Designed by Andrew Plotkin <erkyrath@eblong.com>
    http://eblong.com/zarf/glk/
*/

/* This header defines an interface that must be used by program linked
    with the various Unix Glk libraries -- at least, the three I wrote.
    (I encourage anyone writing a Unix Glk library to use this interface,
    but it's not part of the Glk spec.)
    
    Because Glk is *almost* perfectly portable, this interface *almost*
    doesn't have to exist. In practice, it's small.

    (Except for autosave. That makes everything complicated.)
*/

#ifndef GT_START_H
#define GT_START_H

/* We define our own TRUE and FALSE and NULL, because ANSI
    is a strange world. */
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef NULL
#define NULL 0
#endif

#define glkunix_arg_End (0)
#define glkunix_arg_ValueFollows (1)
#define glkunix_arg_NoValue (2)
#define glkunix_arg_ValueCanFollow (3)
#define glkunix_arg_NumberValue (4)

typedef struct glkunix_argumentlist_struct {
    char *name;
    int argtype;
    char *desc;
} glkunix_argumentlist_t;

typedef struct glkunix_startup_struct {
    int argc;
    char **argv;
} glkunix_startup_t;

extern glkunix_argumentlist_t glkunix_arguments[];

/* defined in unixstrt.c */
extern int glkunix_startup_code(glkunix_startup_t *data);

extern void glkunix_set_base_file(char *filename);
extern strid_t glkunix_stream_open_pathname_gen(char *pathname, 
    glui32 writemode, glui32 textmode, glui32 rock);
extern strid_t glkunix_stream_open_pathname(char *pathname, glui32 textmode, 
    glui32 rock);

/* This library offers the hooks necessary for an interpreter to
   implement autosave. */
#define GLKUNIX_AUTOSAVE_FEATURES (1)

#ifdef GLKUNIX_AUTOSAVE_FEATURES

/* defined in unixstrt.c */
extern void glkunix_do_autosave(glui32 eventaddr);

extern glui32 glkunix_get_last_event_type(void);
extern glui32 glkunix_window_get_updatetag(winid_t win);
extern winid_t glkunix_window_find_by_updatetag(glui32 tag);
extern glui32 glkunix_stream_get_updatetag(strid_t str);
extern strid_t glkunix_stream_find_by_updatetag(glui32 tag);
extern glui32 glkunix_fileref_get_updatetag(frefid_t fref);
extern frefid_t glkunix_fileref_find_by_updatetag(glui32 tag);

#endif /* GLKUNIX_AUTOSAVE_FEATURES */

#endif /* GT_START_H */

