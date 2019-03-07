#include<iostream>
using namespace std;

class Car{
		int gasolineGauge;
	public:
		Car(int gasGauge)
			:gasolineGauge(gasGauge)
		{
			return ;
		}
		~Car()
		{
			return ;
		}
		int GetGasGauge(){
			return gasolineGauge;
		}
};

class HybirdCar : public Car{
		int electricGauge;
	public:
		HybirdCar(int gasGauge, int elecGauge)
			:Car(gasGauge), electricGauge(elecGauge)
		{
			return ;
		}
		~HybirdCar()
		{
			return ;
		}
		int GetElecGauge(){
			return electricGauge;
		}
};
class HybridWaterCar : public HybirdCar{
	private:
		int waterGauge;
	public:
		HybridWaterCar(int gasGauge, int elecGauge, int waterGauge)
			:HybirdCar(gasGauge, elecGauge), waterGauge(waterGauge)
		{
			return ;
		}
		~HybridWaterCar()
		{
			return ;
		}
		void ShowCurrentGauge(){
			cout<<GetGasGauge()<<endl;
			cout<<GetElecGauge()<<endl;
			cout<<waterGauge<<endl;
			}
};

int main(void)
{
	Car car(1);
	HybirdCar hcar(2, 2);
	HybridWaterCar hwcar(3, 3, 3);
	hwcar.ShowCurrentGauge();
}