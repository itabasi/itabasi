

void check_pfer(){

  string  pname="param/3he_ita.dat";
  //    string  pname="param/he3_theory.dat";
  //  pname="param/test2.dat";
  ifstream ifp(pname.c_str());
  double mom[2000],ratio[2000];
  double err[2000];
  string buf;
  string mom_st,ratio_st;
  string err_st;
  int i=0;
  double Ans=0;
  double ans;
  TGraphErrors* gQF=new TGraphErrors();
  gQF->SetTitle("3He Fermi mom distribution ; p_{M} [MeV/c]; probability");
  gQF->SetMarkerColor(2);
  gQF->SetMarkerStyle(20);
  gQF->SetMarkerSize(0.5);
  while( ifp.eof()==0){
    err[i]=0.0;
    mom[i]=0.0;
    ratio[i]=0.0;




    getline(ifp,buf);
    if(buf.length()<5)break;
    ans=0.0;
    mom_st=buf.substr(2,3);
    ratio_st=buf.substr(7,12);
    err_st=buf.substr(21,10);


    mom[i]   = stod(mom_st)*200.;
    ratio[i] = stod(ratio_st);
    err[i] = stod(err_st);
    if(i!=0)ans=4*3.14/pow(3.14*2.0,3)*ratio[i]*(mom[i]-mom[i-1])*mom[i]*mom[i]/pow(200.,3.);
    Ans+=ans/1.354;
    gQF->SetPoint(i,mom[i],ans);


    //    cout<<"i "<<i<<" ratio "<<ans<<" mom "<<mom[i]<<endl;
    i++;

  }



  //  string  pname2="../BackUP/he3.dat";
  //  pname2 ="../he3_simc2.dat";
  string pname2 ="param/test3.dat";
  ifstream ifp2(pname2.c_str());
  double order[2000];
  string order_st;
  TGraphErrors* gQF2=new TGraphErrors();
  gQF2->SetTitle("3He Fermi mom distribution ; p_{M} [MeV/c]; probability");
  gQF2->SetMarkerColor(4);
  gQF2->SetMarkerStyle(20);  
  gQF2->SetMarkerSize(0.3);

  i=0;
  while( ifp2.eof()==0){
    order[i]=0.0;
    mom[i]=0.0;
    ratio[i]=0.0;

    getline(ifp2,buf);
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

    if(i==0)gQF2->SetPoint(i,mom[i],ratio[i]);
    else gQF2->SetPoint(i,mom[i],(ratio[i]-ratio[i-1])*53.);

    //    cout<<"i "<<i<<" ratio "<<ratio[i]<<" mom "<<mom[i]<<endl;
    i++;

  }




  TCanvas* c0 =new TCanvas("c0","c0");
  c0->cd();
  gQF->Draw("AP");
  gQF2->Draw("P");



}
