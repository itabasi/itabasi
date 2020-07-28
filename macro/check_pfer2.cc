

void check_pfer2(){


  string pname ="param/test3.dat";
  ifstream ifp(pname.c_str());
  double mom[2000],ratio[2000];
  double err[2000];
  string buf;
  string mom_st,ratio_st;
  string err_st;
  double Ans=0;
  double ans;
  double order[2000];
  string order_st;
  
  TGraphErrors* gQF=new TGraphErrors();
  gQF->SetTitle("3He Fermi mom distribution ; p_{M} [MeV/c]; probability");
  gQF->SetMarkerColor(2);
  gQF->SetMarkerStyle(20);  
  gQF->SetMarkerSize(0.3);

  int i=0;
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
    else gQF->SetPoint(i,mom[i],(ratio[i]-ratio[i-1])*53.);


    i++;

  }



  

  string  pname2="../BackUP/he3.dat";
  //  pname2 ="../he3_bob.dat";
  
  ifstream ifp2(pname2.c_str());
  //  double order[2000];
  //  string order_st;
  TGraphErrors* gQF2=new TGraphErrors();
  gQF2->SetTitle("3He Fermi mom distribution ; p_{M} [MeV/c]; probability");
  gQF2->SetMarkerColor(4);
  gQF2->SetMarkerStyle(20);  
  gQF2->SetMarkerSize(0.3);

  int   j=0;
  while( ifp2.eof()==0){
    order[j]=0.0;
    mom[j]=0.0;
    ratio[j]=0.0;

    getline(ifp2,buf);
    if(buf.length()<5)break;
    mom_st=buf.substr(3,16);
    ratio_st=buf.substr(26,17);
    order_st=buf.substr(44,3);
    if(buf.length()>=48) order_st="000";

    mom[j]   = stod(mom_st);
    ratio[j] = stod(ratio_st);
    order[j] = stod(order_st);

    if(order[j]==0)order[j]=1.0;
    else order[j] = pow(10.,order[j]);
    
    ratio[j]= ratio[j] * order[j];

    if(j==0)gQF2->SetPoint(j,mom[j],ratio[j]);
    else gQF2->SetPoint(j,mom[j],(ratio[j]-ratio[j-1])*53.);

    //    cout<<"i "<<i<<" ratio "<<ratio[j]<<" mom "<<mom[j]<<endl;
    j++;

  }




  TCanvas* c0 =new TCanvas("c0","c0");
  c0->cd();
  gQF->Draw("AP");
  gQF2->Draw("P");



}
