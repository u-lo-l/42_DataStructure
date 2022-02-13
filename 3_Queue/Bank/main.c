#include "simutil.h"
#include <time.h>

int main(int argc, char **argv)
{
	srand(time(NULL));

	int customerCount = 0;
	int terminateTime = 0;

	switch (argc)
	{
		case 3 :
			if ((customerCount = atoi(argv[1])) < 0)
				customerCount *= -1;
			if ((terminateTime = atoi(argv[2])) < 10)
				terminateTime = 10;
			break;
		default :
			printf("wrong number of customers and terminate time\n");
			return (EXIT_FAILURE);
	}
	playSimulation(customerCount, terminateTime);
}