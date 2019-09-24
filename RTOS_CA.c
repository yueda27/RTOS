#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/*Function declarations*/
int get_n();
float get_mean(float* inputs, int array_size);
float get_std(float* inputs, int array_size, float mean);
void display(float* inputs, int array_size, float mean, float std);
void print_lines(int array_size);

int x;
char **y;

int main(int argc, char *argv[] )
{
	x = argc;
	y=&argv[0];
    int n, i;
    float *usr_input, mean, std;
//   if(strcmp(argv[1],"--help")==0){
//		printf(" Here is the Documentation  ");
//		exit(1);
//	}
	if(argc>1){
		printf("By command argument\n");
		char **p_to_arg = &y[1];
		while(--argc && (*p_to_arg)[0]=='-'){
			if((*p_to_arg)[1]=='\0'){
				printf("Invalid option \n");
				exit(1);
			}
			switch((*p_to_arg)[1]){
				case 'n' : p_to_arg++;
						   n =atoi(*p_to_arg);					// Convert Character String to Integer [stdlib.h]
						   break;
				default	 :	printf("Invalid option \n");
							exit(1);
			}
			if(n>0){
				if(x!=n+3){
					printf("Didn't input the correct number of data!\n");
					exit(1); 
				}
				break;
			}
		}
		}	
	else
	{	
		printf("By programm input\n");
		n = get_n(); //Get size of input for user
	}
	
    if((usr_input=(float*)malloc(n*sizeof(float))) == NULL){ //Memory allocation
        printf("Not enough memory. Use a smaller data size.");
    }
    if(argc>1){
    	int j=0;
        char **p_to_arg = &y[3];
    	for(j=0;j<n;j++){
			usr_input[j]=atof(*p_to_arg);
			p_to_arg++;
		}
	}
	else {
	    for(i=0; i < n; i++){
	        while(1){  //Get number of inputs from user
	
	        printf("Enter value of %d/%d: ", (i+1), n);
	        if(scanf("%f", &usr_input[i]) == 1) //Check if input value from reader is a valid float type 
	        {
	            fseek(stdin,0,SEEK_END);
	            break; //Break out of while loop
	        }
	        //Error block to catch for non float value
	        printf("Error. You did not enter number. Please enter a number\n");
	        fseek(stdin,0,SEEK_END);
	        }
	    }
	}
    mean = get_mean(usr_input, n);
    std = get_std(usr_input, n, mean);
    display(usr_input, n, mean, std);
    free(usr_input); //Clear malloc

    //printf("%f", std);
    

}

int get_n()
{
    /*Macro to get size of input from user*/
    int n;
    while(1){  //Get number of inputs from user

        printf("Input the number of data points to be computed: ");
        if(scanf("%d", &n) == 1 && n > 0) //Check if input value from reader is a valid float type and more than 0
        {
            fseek(stdin,0,SEEK_END);
            break; //Break out of while loop
        }
        // Error block
        else if (n <= 0)
        {
            printf("You entered a negative value. Please enter a value more than 0.\n");  //Check for negative value
            fseek(stdin,0,SEEK_END);
        }
        else{
        printf("Error. You did not enter a whole number. Please enter a whole number value.\n"); //Catch block for other errors: Wrong type of data eg:str
        fseek(stdin,0,SEEK_END);
        }
    }
    return n;
}

float get_mean(float* inputs, int array_size){
    /*Macro to get the mean value.
    ------------------------------
    inputs: float pointer to user input of float[]
    array_size: Int value of the size of array*/
    int i;
    float sum = 0;
 
    for (i = 0; i < array_size; i++)
    {
        sum += inputs[i];
    }
 return sum/array_size;
}

float get_std(float* inputs, int array_size, float mean){
    /*Macro to get standard deviation
    -----------------------------------
    inputs: float pointer to user input of float[]
    array_size: Int value of the size of array
    mean: float mean of inputs*/
    float std, sum;
    int i;
    for (i = 0; i < array_size; i++)
    {
        sum += pow((inputs[i] - mean), 2);
    }
    return sqrt(sum/array_size);
}

void display(float* inputs, int array_size, float mean, float std){
    /* Macro to format display
    --------------------------
    inputs: float pointer to user input of float[]
    array_size: Int value of the size of array
    mean: float mean of inputs
    std: float of standard deviation of inputs*/
    int i;
    print_lines(array_size);
    printf("Results\n");
    print_lines(array_size);
    printf("Your %d inputs are: ", array_size);
    for (i = 0; i < array_size; i++)
    {
        printf("%.2f, ", inputs[i]);
    }
    printf("\n");
    print_lines(array_size);
    printf("Mean of the inputs is %.3f\n", mean);
    printf("Standard deviation of the inputs is %.3f\n", std);
    print_lines(array_size);
}

void print_lines(int array_size){
    /*Function to print lines in relation to array size for display()
    -----------------------------------------------------------------
    array_size: int of size of user input*/
    int i;
    for (i = 0; i < array_size; i++)
    {
        printf("------------------");
    }
    printf("\n");
}
