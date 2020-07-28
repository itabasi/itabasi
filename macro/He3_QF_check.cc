#include <iostream>
#include <fstream>  
#include <string>  
using namespace std;                                                            
                    
void He3_QF_check(){

  string  pname="../BackUP/he3.dat";
  //string  pname="param/3he_remake.dat";
  ifstream ifp(pname.c_str());

  double mom[2000],ratio[2000];
  double order[2000];
  string buf;
  string mom_st,ratio_st;
  string order_st;
  int i=0;

  TGraphErrors* gQF=new TGraphErrors();
  gQF->SetTitle("3He Fermi mom distribution ; p_{M} [MeV/c]; probability");
  gQF->SetMarkerColor(1);
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
    //    cout<<"mom_st "<<mom_st<<" ratio_st "<<ratio_st<<" order_st "<<order_st<<endl;
    if(order[i]==0)order[i]=1.0;
    else order[i] = pow(10.,order[i]);
    
    ratio[i]= ratio[i] * order[i];

    if(i==0)gQF->SetPoint(i,mom[i],ratio[i]);
    else gQF->SetPoint(i,mom[i],ratio[i]-ratio[i-1]);

    //    cout<<"mom "<<mom[i]<<" ratio "<<ratio[i]<<" order "<<order[i]<<endl;
    i++;

  }



  //====== second pictures ========//



  string  pname2="param/3he_remake.dat";
  ifstream ifp2(pname2.c_str());

  double mom2[2000],ratio2[2000];
  double order2[2000];
  string buf2;
  string mom_st2,ratio_st2;
  string order_st2;
  i=0;

  TGraphErrors* gQF2=new TGraphErrors();
  gQF2->SetTitle("3He Fermi mom distribution ; p_{M} [MeV/c]; probability");
  gQF2->SetMarkerColor(2);
  while( ifp2.eof()==0){
    order2[i]=0.0;
    mom2[i]=0.0;
    ratio2[i]=0.0;
    getline(ifp2,buf2);
    if(buf2.length()<5)break;
    mom_st2=buf2.substr(3,16);
    ratio_st2=buf2.substr(26,17);
    order_st2=buf2.substr(44,3);
    if(buf2.length()>=48) order_st2="000";

    mom2[i]   = stod(mom_st2);
    ratio2[i] = stod(ratio_st2);
    order2[i] = stod(order_st2);
    //    cout<<"mom_st "<<mom_st<<" ratio_st "<<ratio_st<<" order_st "<<order_st<<endl;
    if(order2[i]==0)order2[i]=1.0;
    else order2[i] = pow(10.,order2[i]);
    
    ratio2[i]= ratio2[i] * order2[i];

    if(i==0)gQF2->SetPoint(i,mom2[i],ratio2[i]);
    else gQF2->SetPoint(i,mom2[i],ratio2[i]-ratio2[i-1]);

    //    cout<<"i"<<i<<" mom "<<mom[i]<<" ratio "<<ratio[i]<<" order "<<order[i]<<endl;
    i++;

  }

  





  //======== 3rd pictures =========//


  string  pname3="param/3he_remake2.dat";
  ifstream ifp3(pname3.c_str());

  double mom3[2000],ratio3[2000];
  double order3[2000];
  string buf3;
  string mom_st3,ratio_st3;
  string order_st3;
  i=0;

  TGraphErrors* gQF3=new TGraphErrors();
  gQF3->SetTitle("3He Fermi mom distribution ; p_{M} [MeV/c]; probability");
  gQF3->SetMarkerColor(4);
  while( ifp3.eof()==0){
    order3[i]=0.0;
    mom3[i]=0.0;
    ratio3[i]=0.0;

    getline(ifp3,buf3);
    if(buf3.length()<5)break;
    mom_st3=buf3.substr(3,16);
    ratio_st3=buf3.substr(26,17);
    order_st3=buf3.substr(44,3);
    if(buf3.length()>=48) order_st3="000";

    mom3[i]   = stod(mom_st3);
    ratio3[i] = stod(ratio_st3);
    order3[i] = stod(order_st3);
    //    cout<<"mom_st "<<mom_st<<" ratio_st "<<ratio_st<<" order_st "<<order_st<<endl;
    if(order3[i]==0)order3[i]=1.0;
    else order3[i] = pow(10.,order3[i]);
    
    ratio3[i]= ratio3[i] * order3[i];

    if(i==0)gQF3->SetPoint(i,mom3[i],ratio3[i]);
    else gQF3->SetPoint(i,mom3[i],ratio3[i]-ratio3[i-1]);

    //    cout<<"mom "<<mom[i]<<" ratio "<<ratio[i]<<" order "<<order[i]<<endl;
    i++;

  }

  






  
  TCanvas* c0 =new TCanvas("c0","c0");
  c0->cd();
  gQF->Draw("AP");
  gQF2->Draw("P");
  //  gQF3->Draw("P");

}
