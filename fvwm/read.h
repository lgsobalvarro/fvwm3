#ifndef FVWM_READ_H
#define FVWM_READ_H


/**
 * Full pathname of file read in progress, or NULL.
 **/
extern const char *get_current_read_file(void);
extern const char *get_current_read_dir(void);


/**
 * Read and execute each line from stream.
 *
 * Parameters eventp, fw, context, and Module supply the context
 * for executing the commands.
 **/
extern void run_command_stream(
	FILE* f, const XEvent *eventp, FvwmWindow *fw,
	unsigned long context, int Module );


/**
 * Given a filename, open it and execute the commands therein.
 *
 * If the filename is not an absolute path, search for it in
 * fvwm_userdir (set in main()) or in FVWM_DATADIR.  Return TRUE
 * if the file was found and executed.
 **/
extern int run_command_file(
	char* filename, const XEvent *eventp, FvwmWindow *fw,
	unsigned long context, int Module );

#endif
