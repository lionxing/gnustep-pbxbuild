/*
  File autogenerated by gengetopt version 2.18
  generated with the following command:
  gengetopt --input=optionsparser.ggo 

  The developers of gengetopt consider the fixed text that goes in all
  gengetopt output files to be in the public domain:
  we make no copyright claims on it.
*/

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getopt.h"

#include "cmdline.h"

const char *gengetopt_args_info_purpose = "This program builds Xcode projects by converting it to a GNUmakefile";

const char *gengetopt_args_info_usage = "Usage: pbxbuild [OPTIONS]...";

const char *gengetopt_args_info_help[] = {
  "  -h, --help                    Print help and exit",
  "  -V, --version                 Print version and exit",
  "  -p, --project=STRING          The Project to build (.xcode, .xcodeproj)",
  "  -g, --generate-makefile-only  This only generates project makefiles without \n                                  running make  (default=off)",
  "  -d, --debug                   Turn on debug logging  (default=off)",
    0
};

static
void clear_given (struct gengetopt_args_info *args_info);
static
void clear_args (struct gengetopt_args_info *args_info);

static int
cmdline_parser_internal (int argc, const char **argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required, const char *additional_error);


static char *
gengetopt_strdup (const char *s);

static
void clear_given (struct gengetopt_args_info *args_info)
{
  args_info->help_given = 0 ;
  args_info->version_given = 0 ;
  args_info->project_given = 0 ;
  args_info->generate_makefile_only_given = 0 ;
  args_info->debug_given = 0 ;
}

static
void clear_args (struct gengetopt_args_info *args_info)
{
  args_info->project_arg = NULL;
  args_info->project_orig = NULL;
  args_info->generate_makefile_only_flag = 0;
  args_info->debug_flag = 0;
  
}

static
void init_args_info(struct gengetopt_args_info *args_info)
{
  args_info->help_help = gengetopt_args_info_help[0] ;
  args_info->version_help = gengetopt_args_info_help[1] ;
  args_info->project_help = gengetopt_args_info_help[2] ;
  args_info->generate_makefile_only_help = gengetopt_args_info_help[3] ;
  args_info->debug_help = gengetopt_args_info_help[4] ;
  
}

void
cmdline_parser_print_version (void)
{
  printf ("%s %s\n", CMDLINE_PARSER_PACKAGE, CMDLINE_PARSER_VERSION);
}

void
cmdline_parser_print_help (void)
{
  int i = 0;
  cmdline_parser_print_version ();

  if (strlen(gengetopt_args_info_purpose) > 0)
    printf("\n%s\n", gengetopt_args_info_purpose);

  printf("\n%s\n\n", gengetopt_args_info_usage);
  while (gengetopt_args_info_help[i])
    printf("%s\n", gengetopt_args_info_help[i++]);
}

void
cmdline_parser_init (struct gengetopt_args_info *args_info)
{
  clear_given (args_info);
  clear_args (args_info);
  init_args_info (args_info);
}

static void
cmdline_parser_release (struct gengetopt_args_info *args_info)
{
  
  if (args_info->project_arg)
    {
      free (args_info->project_arg); /* free previous argument */
      args_info->project_arg = 0;
    }
  if (args_info->project_orig)
    {
      free (args_info->project_orig); /* free previous argument */
      args_info->project_orig = 0;
    }
  
  clear_given (args_info);
}

int
cmdline_parser_file_save(const char *filename, struct gengetopt_args_info *args_info)
{
  FILE *outfile;
  int i = 0;

  outfile = fopen(filename, "w");

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot open file for writing: %s\n", CMDLINE_PARSER_PACKAGE, filename);
      return EXIT_FAILURE;
    }

  if (args_info->help_given) {
    fprintf(outfile, "%s\n", "help");
  }
  if (args_info->version_given) {
    fprintf(outfile, "%s\n", "version");
  }
  if (args_info->project_given) {
    if (args_info->project_orig) {
      fprintf(outfile, "%s=\"%s\"\n", "project", args_info->project_orig);
    } else {
      fprintf(outfile, "%s\n", "project");
    }
  }
  if (args_info->generate_makefile_only_given) {
    fprintf(outfile, "%s\n", "generate-makefile-only");
  }
  if (args_info->debug_given) {
    fprintf(outfile, "%s\n", "debug");
  }
  
  fclose (outfile);

  i = EXIT_SUCCESS;
  return i;
}

void
cmdline_parser_free (struct gengetopt_args_info *args_info)
{
  cmdline_parser_release (args_info);
}


/* gengetopt_strdup() */
/* strdup.c replacement of strdup, which is not standard */
char *
gengetopt_strdup (const char *s)
{
  char *result = NULL;
  if (!s)
    return result;

  result = (char*)malloc(strlen(s) + 1);
  if (result == (char*)0)
    return (char*)0;
  strcpy(result, s);
  return result;
}

int
cmdline_parser (int argc, char const *argv[], struct gengetopt_args_info *args_info)
{
  return cmdline_parser2 (argc, argv, args_info, 0, 1, 1);
}

int
cmdline_parser2 (int argc, const char **argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required)
{
  int result;

  result = cmdline_parser_internal (argc, argv, args_info, override, initialize, check_required, NULL);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser_required (struct gengetopt_args_info *args_info, const char *prog_name)
{
  return EXIT_SUCCESS;
}

int
cmdline_parser_internal (int argc, const char **argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required, const char *additional_error)
{
  int c;	/* Character of the parsed option.  */

  int error = 0;
  struct gengetopt_args_info local_args_info;

  if (initialize)
    cmdline_parser_init (args_info);

  cmdline_parser_init (&local_args_info);

  optarg = 0;
  optind = 0;
  opterr = 1;
  optopt = '?';

  while (1)
    {
      int option_index = 0;
      char *stop_char;

      static struct option long_options[] = {
        { "help",	0, NULL, 'h' },
        { "version",	0, NULL, 'V' },
        { "project",	1, NULL, 'p' },
        { "generate-makefile-only",	0, NULL, 'g' },
        { "debug",	0, NULL, 'd' },
        { NULL,	0, NULL, 0 }
      };

      stop_char = 0;
      c = getopt_long (argc, (char * const*)argv, "hVp:gd", long_options, &option_index);

      if (c == -1) break;	/* Exit from `while (1)' loop.  */

      switch (c)
        {
        case 'h':	/* Print help and exit.  */
          cmdline_parser_print_help ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'V':	/* Print version and exit.  */
          cmdline_parser_print_version ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'p':	/* The Project to build (.xcode, .xcodeproj).  */
          if (local_args_info.project_given)
            {
              fprintf (stderr, "%s: `--project' (`-p') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->project_given && ! override)
            continue;
          local_args_info.project_given = 1;
          args_info->project_given = 1;
          if (args_info->project_arg)
            free (args_info->project_arg); /* free previous string */
          args_info->project_arg = gengetopt_strdup (optarg);
          if (args_info->project_orig)
            free (args_info->project_orig); /* free previous string */
          args_info->project_orig = gengetopt_strdup (optarg);
          break;

        case 'g':	/* This only generates project makefiles without running make.  */
          if (local_args_info.generate_makefile_only_given)
            {
              fprintf (stderr, "%s: `--generate-makefile-only' (`-g') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->generate_makefile_only_given && ! override)
            continue;
          local_args_info.generate_makefile_only_given = 1;
          args_info->generate_makefile_only_given = 1;
          args_info->generate_makefile_only_flag = !(args_info->generate_makefile_only_flag);
          break;

        case 'd':	/* Turn on debug logging.  */
          if (local_args_info.debug_given)
            {
              fprintf (stderr, "%s: `--debug' (`-d') option given more than once%s\n", argv[0], (additional_error ? additional_error : ""));
              goto failure;
            }
          if (args_info->debug_given && ! override)
            continue;
          local_args_info.debug_given = 1;
          args_info->debug_given = 1;
          args_info->debug_flag = !(args_info->debug_flag);
          break;


        case 0:	/* Long option with no short option */
        case '?':	/* Invalid option.  */
          /* `getopt_long' already printed an error message.  */
          goto failure;

        default:	/* bug: option not considered.  */
          fprintf (stderr, "%s: option unknown: %c%s\n", CMDLINE_PARSER_PACKAGE, c, (additional_error ? additional_error : ""));
          abort ();
        } /* switch */
    } /* while */




  cmdline_parser_release (&local_args_info);

  if ( error )
    return (EXIT_FAILURE);

  return 0;

failure:
  
  cmdline_parser_release (&local_args_info);
  return (EXIT_FAILURE);
}
