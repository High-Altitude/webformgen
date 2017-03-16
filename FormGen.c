#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void displayhelp()
    {
        printf("\nUsage: FormGen.exe <-s [ID] [Value]> <-t [Label-Name]> <-m [Label-Name]> <-c [Label-Name] [Value]> <-h [Name][Value]><-b [Click]] [Value]> <-f [Label-Name]> [-a Action]\n");
        printf("\n");
        printf("    ID      required. ID of control.\n");
        printf("    Label   required. Label caption.\n");
        printf("    Action  required. path to file that will handle the post action.\n");
        printf("    Value   required. Value of control.\n");
        printf("    Name    required. Name of control.\n");
        printf("    click   required. On click action handler file path.\n");
        printf("    -f      optional. File picker.\n");
        printf("    -t      optional. Text box region.\n");
        printf("    -s      optional. Submit button.\n");
        printf("    -r      optional. Radio button.\n");
        printf("    -m      optional. Multi line text area.\n");
        printf("    -c      optional. Check box input region.\n");
        printf("    -h      optional. Hidden input.\n");
        printf("    -b      optional. Button with which to trigger action handler file.\n");
        printf("    -p      optional. password box input region.\n");
        printf("    -a      required. Action indicator for the form.\n");
        printf("\n");
        printf("use example: FormGen.exe -t User_name -P password -s Submit -a /DoScrpt.php\n");
        printf("NOTE: All underscores will be replaced with spaces in the visible form.\n");
    }
int main( int argc, char *argv[] )
    {
        if( (argc == 3 && strncmp(argv[1],"-a",2) != 0) ||  argc == 1)
            {
                printf("\nAt least the action \"-a\" argument is required.");
                displayhelp();
                return 1;
            }
        char * build;
        build = (char*) malloc(0*sizeof(build));
        strcpy(build, "");
        int action = 0;
        int loopnum;
        int label;
        int newsize = 0;
        int value;
        char actiondef[50];
        char css[] = "<style>\
             form {\
              /* Just to center the form on the page */\
              margin: 0 auto;\
              width: 305px;\
            \
              /* To see the limits of the form */\
              padding: 1em;\
              border: 1px solid #CCC;\
              border-radius: 1em;\
            }\
            \
            div + div {\
              margin-top: 1em;\
            }\
            \
            label {\
              /* To make sure that all label have the same size and are properly align */\
              display: inline-block;\
              text-align: left;\
            }\
            \
            input, textarea {\
              /* To make sure that all text field have the same font settings\
                 By default, textarea are set with a monospace font */\
              font: 1em sans-serif;\
            \
              /* To give the same size to all text field */\
              width: 300px;\
            \
              -moz-box-sizing: border-box;\
                   box-sizing: border-box;\
            \
              /* To harmonize the look & feel of text field border */\
              border: 1px solid #999;\
              display: inline;\
            }\
            \
            input[type=\"checkbox\"]{\
                width: auto;\
            }\
            input[type=\"radio\"]{\
                width: auto;\
            }\
            \
            \
            input:focus, textarea:focus {\
              /* To give a little highligh on active elements */\
              border-color: #000;\
            }\
            \
            textarea {\
              /* To properly align multiline text field with their label */\
              vertical-align: top;\
            \
              /* To give enough room to type some text */\
              height: 5em;\
            \
              /* To allow users to resize any textarea vertically\
                 It works only on Chrome, Firefox and Safari */\
              resize: vertical;\
            }\
            \
            .button {\
              /* To position the buttons to the same position of the text fields */\
              padding-left: 90px; /* same size as the label elements */\
            }\
            \
            button {\
              /* This extra magin represent the same space as the space between\
                 the labels and their text fields */\
              margin-left: .5em;\
            }\
            </style>";
        for( loopnum = 1; loopnum < argc; loopnum = loopnum + 1 )
            {
                if(strlen(argv[loopnum]) == 2)
                    {
                        if(strncmp(argv[loopnum],"-",1) == 0 )
                            {
                                label = loopnum + 1;
                                value = loopnum + 2;
                                if(strncmp(argv[loopnum],"-t",2) == 0 )
                                    {
                                        newsize = 1
                                        + strlen(build)
                                        + strlen("\t<div>\n\t\t<label for=\"")
                                        + strlen(argv[label])
                                        + strlen("\">") + strlen(argv[label])
                                        + strlen("</label>\n")
                                        + strlen("\t\t<input type=\"text\" id=\"")
                                        + strlen(argv[label])
                                        + strlen("\" name=\"")
                                        + strlen(argv[label])
                                        + strlen("\">\n\t</div>\n");
                                        build = (char*) realloc(build, newsize * sizeof(char));
                                        strcat(build, "\t<div>\n\t\t<label for=\"");
                                        strcat(build, argv[label]);
                                        strcat(build, "\">");
                                        strcat(build, argv[label]);
                                        strcat(build, "</label>\n");
                                        strcat(build, "\t\t<input type=\"text\" id=\"");
                                        strcat(build, argv[label]);
                                        strcat(build, "\" name=\"");
                                        strcat(build, argv[label]);
                                        strcat(build, "\">\n\t</div>\n\0");

                                    }
                                if(strncmp(argv[loopnum],"-r",2) == 0 )
                                    {
                                        newsize = 1
                                        + strlen(build)
                                        + strlen("\t<div>\n\t\t<input type=\"radio\" id=\"")
                                        + strlen(argv[label])
                                        + strlen("\" name=\"")
                                        + strlen(argv[label])
                                        + strlen("\" value=\"")
                                        + strlen(argv[value])
                                        + strlen("\">\n")
                                        + strlen("\t\t<label for=\"")
                                        + strlen(argv[label])
                                        + strlen("\">")
                                        + strlen(argv[label])
                                        + strlen("</label>\n\t</div>\n");
                                        build = (char*) realloc(build, newsize * sizeof(char));
                                        strcat(build, "\t<div>\n\t\t<input type=\"radio\" id=\"");
                                        strcat(build, argv[label]);
                                        strcat(build, "\" name=\"");
                                        strcat(build, argv[label]);
                                        strcat(build, "\" vlaue=\"");
                                        strcat(build, argv[value]);
                                        strcat(build, "\">\n\t\t<label for=\"");
                                        strcat(build, argv[label]);
                                        strcat(build, "\">");
                                        strcat(build, argv[label]);
                                        strcat(build, "</label>\n\t</div>\n\0");
                                    }
                                if(strncmp(argv[loopnum],"-m",2) == 0 )
                                    {
                                        //strcpy(columns, argv[value]);
                                        //cols = atoi(columns);
                                        //cols = cols * 2;
                                        //sprintf(columns, "%d", cols);
                                        newsize = 1
                                        + strlen(build)
                                        + strlen("\t<div>\n\t\t<label for=\"")
                                        + strlen(argv[label]) + strlen("\">")
                                        + strlen(argv[label])
                                        + strlen("</label>\n")
                                        + strlen("\t\t<textarea name=\"")
                                        + strlen(argv[label])
                                        + strlen("\"></textarea>\n\t</div>\n");
                                        build = (char*) realloc(build, newsize * sizeof(char));
                                        strcat(build, "\t<div>\n\t\t<label for=\"");
                                        strcat(build, argv[label]);
                                        strcat(build, "\">");
                                        strcat(build, argv[label]);
                                        strcat(build, "</label>\n");
                                        strcat(build, "\t\t<textarea name=\"");
                                        strcat(build, argv[label]);
                                        strcat(build, "\"></textarea>\n\t</div>\n\0");
                                    }
                                    if(strncmp(argv[loopnum],"-f",2) == 0 )
                                    {
                                        newsize = 1
                                        + strlen(build)
                                        + strlen("\t<div>\n\t\t<label for=\"")
                                        + strlen(argv[label]) + strlen("\">")
                                        + strlen(argv[label])
                                        + strlen("</label>\n")
                                        + strlen("\t\t<input type=\"file\" name=\"")
                                        + strlen(argv[label])
                                        + strlen("\">\n\t</div>\n");
                                        build = (char*) realloc(build, newsize * sizeof(char));
                                        strcat(build, "\t<div>\n\t\t<label for=\"");
                                        strcat(build, argv[label]);
                                        strcat(build, "\">");
                                        strcat(build, argv[label]);
                                        strcat(build, "</label>\n");
                                        strcat(build, "\t\t<input type=\"file\" name=\"");
                                        strcat(build, argv[label]);
                                        strcat(build, "\">\n\t</div>\n\0");
                                    }
                                if (strncmp(argv[loopnum],"-h",2) == 0 )
                                    {
                                        newsize = 1
                                        + strlen(build)
                                        + strlen("\t<div>\n\t\t<input type=\"hidden\" id=\"")
                                        + strlen(argv[label])
                                        + strlen("\" name=\"")
                                        + strlen(argv[value])
                                        + strlen("\" value=\"")
                                        + strlen(argv[label])
                                        + strlen("\">\n\t</div>\n");
                                        build = (char*) realloc(build, newsize * sizeof(char));
                                        strcat(build, "\t<div>\n\t\t<input type=\"hidden\" id=\"");
                                        strcat(build, argv[label]);
                                        strcat(build, "\" name=\"");
                                        strcat(build, argv[label]);
                                        strcat(build, "\" vlaue=\"");
                                        strcat(build, argv[value]);
                                        strcat(build, "\">\n\t</div>\n\0");
                                    }
                                if (strncmp(argv[loopnum],"-c",2) == 0 )
                                    {
                                        newsize = 1 + strlen(build)
                                        + strlen("\t<div>\n\t\t<input type=\"checkbox\" id=\"")
                                        + strlen(argv[label])
                                        + strlen("\" name=\"")
                                        + strlen(argv[label])
                                        + strlen("\" value=\"")
                                        + strlen(argv[value])
                                        + strlen("\">\n")
                                        + strlen("\t\t<label for=\"")
                                        + strlen(argv[label])
                                        + strlen("\">")
                                        + strlen(argv[label])
                                        + strlen("</label>\n\t</div>\n");
                                        build = (char*) realloc(build, newsize * sizeof(char));
                                        strcat(build, "\t<div>\n\t\t<input type=\"checkbox\" id=\"");
                                        strcat(build, argv[label]);
                                        strcat(build, "\" name=\"");
                                        strcat(build, argv[label]);
                                        strcat(build, "\" vlaue=\"");
                                        strcat(build, argv[value]);
                                        strcat(build, "\">\n\t\t<label for=\"");
                                        strcat(build, argv[label]);
                                        strcat(build, "\">");
                                        strcat(build, argv[label]);
                                        strcat(build, "</label>\n\0");
                                    }
                                if(strncmp(argv[loopnum],"-s",2) == 0 )
                                    {
                                        newsize = 1
                                        + strlen(build)
                                        + strlen("\t<div>\n")
                                        + strlen("\t\t<input type=\"submit\" id=\"")
                                        + strlen(argv[label])
                                        + strlen("\" value=\"")
                                        + strlen(argv[label])
                                        + strlen("\">\n\t</div>\n");
                                        build = (char*) realloc(build, newsize * sizeof(char));
                                        strcat(build, "\t<div>\n");
                                        strcat(build, "\t\t<input type=\"submit\" id=\"");
                                        strcat(build, argv[label]);
                                        strcat(build, "\" value=\"");
                                        strcat(build, argv[label]);
                                        strcat(build, "\">\n\t</div>\n\0");
                                    }
                                if(strncmp(argv[loopnum],"-b",2) == 0 )
                                    {
                                        newsize = 1
                                        + strlen(build)
                                        + strlen("\t<div>\n")
                                        + strlen("\t\t<input type=\"button\" onclick=\"")
                                        + strlen(argv[label])
                                        + strlen("\" value=\"")
                                        + strlen(argv[value])
                                        + strlen("\">\n\t</div>\n");
                                        build = (char*) realloc(build, newsize * sizeof(char));
                                        strcat(build, "\t<div>\n");
                                        strcat(build, "\t\t<input type=\"button\" onclick=\"");
                                        strcat(build, argv[label]);
                                        strcat(build, "\" value=\"");
                                        strcat(build, argv[value]);
                                        strcat(build, "\">\n\t</div>\n\0");
                                    }
                                if(strncmp(argv[loopnum],"-p",2) == 0 )
                                    {
                                        newsize = 1
                                        + strlen(build)
                                        + strlen("\t<div>\n\t\t<label for=\"")
                                        + strlen(argv[label])
                                        + strlen("\">")
                                        + strlen(argv[label])
                                        + strlen("</label>\n\t\t<input type=\"password\" id=\"")
                                        + strlen(argv[label])
                                        + strlen("\" name=\"")
                                        + strlen(argv[label])
                                        + strlen("\">\n\t</div>\n");
                                        build = (char*) realloc(build, newsize * sizeof(char));
                                        strcat(build, "\t<div>\n\t\t<label for=\"");
                                        strcat(build, argv[label]);
                                        strcat(build, "\">");
                                        strcat(build, argv[label]);
                                        strcat(build, "</label>\n");
                                        strcat(build, "\t\t<input type=\"password\" id=\"");
                                        strcat(build, argv[label]);
                                        strcat(build, "\" name=\"");
                                        strcat(build, argv[label]);
                                        strcat(build, "\">\n\t</div>\n\0");
                                    }
                                if(strncmp(argv[loopnum],"-a",2) == 0 )
                                    {
                                        action = 1;
                                        strcpy(actiondef, argv[label]);
                                    };
                                newsize = strlen(build);

                            };

                    };
            };
        if(action == 1)
            {
                char output[newsize];
                for( loopnum = 0; loopnum < newsize; loopnum = loopnum + 1)
                    {
                        if(strncmp(&build[loopnum],"_", 1) == 0)
                            {
                                strcpy(&(output[loopnum]), " ");
                            }
                        else
                            {
                                strcpy(&(output[loopnum]), &(build[loopnum]));
                            };
                    };
                printf("%s\n<form action=\"%s\" method=\"post\">\n%s</form>\n\0", css, actiondef, output);
                return 0;
            }
        else
            {
                printf("\nAt least the action \"-a\" argument is required.");
                displayhelp();
                return 1;
            };
    };


