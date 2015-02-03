#include <QtCore/QCoreApplication>
#include "textsplitter.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	textSplitter cutText;
	cutText.RunMe(argc, argv);
	
	return 0;
}
