#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int KiemTraXau(string n)
{
    int str = n.length(), dem = 0;
    for(int i=0;i<str;i++)
    {
        if(n[i]==n[str-i-1])
            dem++;
    }
    if(dem>=3)
        return 1;
    else
        return 0;
}
int main()
{
    string n;
    fstream MyFile;
    MyFile.open("PALIN.txt");
    ofstream File("PALOUT.txt");
    while(!MyFile.eof())
    {
    MyFile >> n;
    File << KiemTraXau(n);
    }
    MyFile.close();
    File.close();
}
