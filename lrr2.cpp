#include <iostream>

using namespace std;

int main (int argc, char **argv)
{
        unsigned int Array[] = {1,45,34,54,32,1,3,5,6,5};
        unsigned int sum1=0, sum2=0;                                                                                                                                                                                                                                                   cout << "Ishodnyi:\tPreobr massiv:" << endl;
        for(unsigned int i=0; i<10;i++)
        {
                sum1+=Array[i];
                cout<<Array[i];
                Array[i] |= 1<<3;
                cout<<"\t\t\t"<<Array[i]<<endl;
                sum2+=Array[i];
        }
        cout<<"\n\nSum:\n" << sum1<<"\t\t\t"<<sum2<<endl;
}
