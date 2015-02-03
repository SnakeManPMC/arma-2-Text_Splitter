#include "textsplitter.h"
#include <QTime>
#include <cstdio>
#include <cstdlib>

textSplitter::textSplitter()
{
}


void textSplitter::RunMe(int argc, char *argv[])
{
	// just get the time
	QTime t;
	t.start();
	char line[1024], MyFileName[50];
	int i = 1, LineCount = 0, NumOfLines = 500;
	
	FILE *map;
	FILE *output;
	
	if (argc < 2)
	{
		printf("Incorrect parameters supplied.\nUsage:\n\nText_Splitter SOURCE.txt <number of lines>\n\nFor example:\n\nText_Splitter my_objects.txt 500\n");
		exit(1);
	}
	
	if (atoi(argv[2]) > 0) NumOfLines = atoi(argv[2]);
	
	map = fopen (argv[1], "rt");
	if (!map)
	{
		printf ("error in %s\n", argv[1]);
		exit (1);
	}
	
	printf ("Opened %s\n", argv[1]);
	
	sprintf (MyFileName, "%s_0%i.txt", argv[1], i);
	output = fopen (MyFileName, "wt");
	if (!output)
	{
		printf ("error at %s file\n", MyFileName);
		exit (1);
	}
	
	fgets (line, 1024, map);
	LineCount++;
	
	while (!feof(map))
	{
		//printf("NumOfLines: %i, LineCount: %i\n", NumOfLines, LineCount);
		
		if (LineCount == NumOfLines)
		{
			LineCount = 0;
			fclose(output);
			i++;
			sprintf (MyFileName, "%s_0%i.txt", argv[1], i);
			output = fopen (MyFileName, "wt");
			if (!output)
			{
				printf ("error at %s file\n", MyFileName);
				exit (1);
			}
		}
		fputs (line, output);
		
		// start new loop
		fgets (line, 1024, map);
		LineCount++;
	}
	
	fclose(output);
	qDebug("Time elapsed: %d ms", t.elapsed());
}
