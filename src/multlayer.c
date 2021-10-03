#include<stdio.h>
#include<process.h>
#include<math.h>

double* hiddenlayer(int size , double *w, double *prev_x, double *bias,int layer)
{
//let previous layer has n*1 neurons
// our layer has size*1 neurons
// weight matrix * previous layer =  []size*n * []n*1 =[] size*1


//weight matrix [w(11) w(21) w(31)]
//              [w(12) w(22) w(32)] w(i=prevs node , j=to new node) 
double *newmatrix,temp=0;
newmatrix =(double* )malloc(size*sizeof(double));
int size_prevx=sizeof(prev_x)/sizeof(double);
int size_w=sizeof(w)/sizeof(double);
//check for compatibilty of weight matrix

if (size*size_prevx != size_w)
{
printf("\nIncorrect size parameters at layer %d",layer);
printf("\nSize of Prev nodes = %d",size_prevx);
printf("\nSize of layer %d is %d",layer,size);
printf("\nSize of of weight matrix is %d but required %d",size_w,Size*size_prevx);
exit(0);
}

for (int i =0; i<size; i++)
{for (int j=0; j<size_prevx; j++)
{ temp+=w[j+size*i]*prev_x[j];}
newmatrix[i]=temp+bias[i];}

return newmatrix;
}

double* inputlayer( int size, double *prev_x, double *bias)
{

int size_prevx=sizeof(prev_x)/sizeof(double);

if (size != size_prevx)
{
printf("\nIncorrect size parameters at input layer ");
printf("\nSize of input nodes = %d",size);
printf("\nSize of data recived = %d",size_prevx);
exit(0);
}


for (int i =0; i<size; i++)
{prev_x[i]+=bias[i];}

return prev_x;
}

double* act_relu(double *prev_x)
{

int size_prevx=sizeof(prev_x)/sizeof(double);

for (int i=0;i<size_prevx;i++)
{if (prev_x[i]>=0)continue;
else prev_x[i]=0;
}

return prev_x;
}


double* act_sigmoid(double *prev_x)
{

int size_prevx=sizeof(prev_x)/sizeof(double);
for(int i=0;i<size;i++)
{
prev_x[i]=1/(1+exp(-prex_x[i]));
}
return prev_x;}



double* act_tanh(double *prev_x)
{
int size_prevx=sizeof(prev_x)/sizeof(double);

for(int i=0;i<size;i++)
{
prev_x[i]=(exp(-prev_x[i])-exp(prev_x[i]))/(exp(-prev_x[i])+exp(prev_x[i]));
}
return prev_x;}

/*

double* act_leakyrelu(double *prev_x)
{ 
int size_prevx=sizeof(prev_x)/sizeof(double);

for(int i=0;i<size;i++)
{ if (
}
return prev_x;
}
*/


