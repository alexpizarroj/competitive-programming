/*
** @author Diego Gabriel Nunhez Duran
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>

using namespace std;

const double EPS = 1e-9;

struct Sphere
{
    double x, y, z, r;

	Sphere(){};
	Sphere(bool t){
		if(t){
			cin>>r>>x>>y>>z;
		//	r *= 1000;
		//	x *= 1000;
		//	y *= 1000;
		//	z *= 1000;
		}
	}

	double volume(){
		return 4.0*r*r*r*acos(-1) / 3.0;
	}

	bool intersects(double a){
		return z-r < a && a < z+r;
	}

	double f(double h){
		//cout<<"h: "<<h<<endl;
		return (acos(-1)*h*h*(3.0*r-h))/3.0;
	}

	double lVolume(double p){
		double res = f(p-(z-r)); 
		//cout<<res<<" ----l "<<endl;
		return res;
	} 

	double rVolume(double p){
		double res = f((z+r)-p); 
		//cout<<res<<" ----r "<<endl;
		return res;
	}
};


int n, s;

double volumeBetween(vector <Sphere> &holes, double ini, double fin){
	double res = 100000.0*100000.0*(fin-ini);

	double tmp = 0.0;	
	//cout<<"tot vol_: "<<res<<endl; 
	for (int i = 0; i < n; i++){
		//cout<<"lala<<"<<endl;
		tmp = 0.0;
		if (holes[i].intersects(ini)){
			//cout<<i<<" touch!!! "<<ini<<endl;
			tmp += holes[i].lVolume(ini);
		}
		if (holes[i].intersects(fin)){

			//cout<<i<<" touch!!! "<<fin<<endl;
			tmp += holes[i].rVolume(fin);
		}
		//cout<<"dif: "<<(holes[i].volume() - tmp)<<endl;
    
    bool contained = true;
    contained &= (ini <= holes[i].z - holes[i].r);
    contained &= (holes[i].z + holes[i].r <= fin);
    
    if (contained || tmp != 0.0)
      res -= (holes[i].volume() - tmp);
	}
	//cout<<"res: "<<res<<endl;
	//cout<<"-------------------------"<<endl<<endl;
	return res;
}

int main(){

	cin>>n>>s;

	vector<Sphere> holes;

	double tot = 0.0;
	for(int i = 0; i < n; i++){
		Sphere s(true);
		holes.push_back(s);
		tot += s.volume();
	}

	double last = 0.0;
	double target = (100000.0*100000.0*100000.0-tot) / s;
	//cout<<target<<endl;
	for (int i = 0; i < s; i++){

		double ini, fin;
		ini = last;
		fin = 100000.0;

		while (fin - ini > EPS){
			//cout<<ini<<" -> "<<fin<<endl;
			double mid = (ini + fin)/2;

			if (volumeBetween(holes, last, mid)<target){
				ini = mid;
			}
			else
				fin = mid;
		}

		printf("%.9lf\n", (ini-last)/1000.0);
		last = ini;
	}

	return 0;
}