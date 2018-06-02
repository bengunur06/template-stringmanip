//this program overloads operators and functions 
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>
#define getmax(a,b)  (((a)>(b)) ? (a) :( b))
using namespace std;

template <typename T>
void sort(T a[],int size)
{
T temp;
for(int i=0;i<size;++i)
{
for(int k=0;k<size-1;++k)
{
if(a[k+1]<a[k])
{
temp=a[k+1];
a[k+1]=a[k];
a[k]=temp;
}
}
}
}

bool isdigit(string a)
{
int c=0;
std::string::iterator it,iit;
iit=a.begin();
if(*iit=='-')
{
	for(it=a.begin()+1;it!=a.end();++it)
	{
	
	if(*it<='9'&&*it>='0')
	
	++c;
	}

	if(c==a.end()-a.begin()-1) return true;
else return false;


}
else 
{
	for(it=a.begin();it!=a.end();++it)
	{
	if(*it<='9'&&*it>='0')
	++c;
	}

if(c==a.end()-a.begin()) return true;
else return false;
}



}

int stringtoint(string a)
{
int number=0;
int x=0;
int tenpower;
int size=a.end()-a.begin();

string::iterator it;
if(*a.begin()=='-')
{

	for(tenpower=1,it=a.end()-1;it!=a.begin();--it,tenpower*=10)
	{
	x=(int)*it-48;
	number+=x*tenpower;


	}
return number*(-1);
}

else 
{

for(tenpower=1,it=a.end()-1;it>=a.begin();--it,tenpower*=10)
{
x=(int)*it-48;
number+=x*tenpower;

}
return number;
}

}

int main()
{
int begin=0,end=0;
string a;
int x=0;


int count=0;
ifstream file("Tdeneme.txt");

if(!file.is_open())
{
cout<<"file is not opened "<<endl;
}
else 
{
begin=file.tellg();
file.seekg(0,ios::end);
end=file.tellg();
file.seekg(ios::beg);
cout<<"file is opened"<<endl;
cout<<"File size is "<<end-begin<<endl;

while(!file.eof())
{
file>>a;
if(isdigit(a))
{
cout<<"---------------------"<<endl;
cout<<a<<endl<<"---------------------"<<endl;
x=stringtoint(a);

cout<<"turned into int "<<x<<endl;
count++;
}
else cout<<"++++++++++++++++++"<<endl<<"Ths is not int :"<<a<<endl<<"++++++++++++++++++"<<endl<<endl;
}
}

cout<<endl<<endl<<endl<<"TAKING INT and SORTING THEM IN AN ARRAY"<<endl<<endl<<endl;
int array[count];
count=0;
file.clear();
file.seekg(ios::beg);

while(!file.eof())
{

file>>a;

if(isdigit(a))
{

x=stringtoint(a);
array[count]=x;
count++;
}
}

for(int i=0;i<count-1;++i)
{
cout<<array[i]<<endl;
}


sort(array,count-1);
cout<<"SORTED ARRAY "<<endl;
for(int i=0;i<count-1;++i)
{
cout<<array[i]<<endl;
}






}


