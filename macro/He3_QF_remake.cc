#include <iostream>
#include <fstream>  
#include <string>  
using namespace std;                                                            
                    
void He3_QF_remake(){

  string  pname="../BackUP/he3.dat";
  //string  pname="param/test3.dat";
  ifstream ifp(pname.c_str());

  double mom[2000],ratio[2000];
  double order[2000];
  string buf;
  string mom_st,ratio_st;
  string order_st;
  int i=0;

  //string ofname ="param/3he_remake.dat";
  string ofname ="param/test2.dat";

  ofstream ofp(ofname.c_str());
  
  TGraphErrors* gQF=new TGraphErrors();
  gQF->SetTitle("3He Fermi mom distribution ; p_{M} [MeV/c]; probability");
  gQF->SetMarkerColor(2);

  TGraphErrors* gQF2=new TGraphErrors();
  gQF2->SetTitle("3He Fermi mom distribution ; p_{M} [MeV/c]; probability");
  gQF2->SetMarkerColor(4);

  int nnn=0;
  while( ifp.eof()==0){
    order[i]=0.0;
    mom[i]=0.0;
    ratio[i]=0.0;

    getline(ifp,buf);
    if(buf.length()<5)break;
    mom_st=buf.substr(3,16);
    ratio_st=buf.substr(26,17);
    order_st=buf.substr(44,3);
    if(buf.length()>=48) order_st="000";

    mom[i]   = stod(mom_st);
    ratio[i] = stod(ratio_st);
    order[i] = stod(order_st);

    if(order[i]==0)order[i]=1.0;
    else order[i] = pow(10.,order[i]);
    
    ratio[i]= ratio[i] * order[i];

    
    if(i==0)gQF->SetPoint(i,mom[i],ratio[i]);
    else gQF->SetPoint(i,mom[i],(ratio[i]-ratio[i-1] ));

    
    if(mom[i]<490.){
      ofp << buf<<endl;
      
    if(i==0)gQF2->SetPoint(i,mom[i],ratio[i]);
    else if(mom[i]<490.) gQF2->SetPoint(i,mom[i],ratio[i]-ratio[i-1]);

    
    }else if(i<995){
      
      //      ratio[i] = ratio[i-1] + (ratio[i] - ratio[i-1])/10.; //test

      for(int j=0;j<=nnn+1;j++){
	if(j==0)ratio[i] =  ratio[i]/10.;
	else if(j<=nnn) ratio[i] +=  - pow(-9.0,j)*ratio[i-j];
	else if(j==nnn+1) ratio[i] +=  - pow(-9.0, j)/10.*ratio[i-j];
      }

      nnn++;
      
      double ratio_c = ratio[i];
      //      double ratio_c = ratio[i-1] + (ratio[i] - ratio[i-1])/10.;
      string ratioc = Form("%.15f",ratio_c);
      string aaa = buf.substr(0,26);

       
      ofp << aaa << ratioc <<"     "<<endl;
      
      gQF2->SetPoint(i,mom[i],ratio_c -ratio[i-1]);
	    //	    cout<<"i "<<i<<" ratioc "<<ratio_c -ratio[i-1]<<" ratio "<<ratio[i]-ratio[i-1]<<endl;
	    cout<<"i "<<i<<" mom "<<aaa<<" ratio "<<ratio[i]<<" ratioc "<<ratioc<<endl; 

    }




    
    i++;

  }



  
  TCanvas* c0 =new TCanvas("c0","c0");
  c0->cd();
  gQF->Draw("AP");
  gQF2->Draw("P");		     

}
