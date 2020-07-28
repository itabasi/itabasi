

void check_3He(){


  //  string root_name ="../rootfiles/3He_kaon.root";
  //  string root_name2 ="../rootfiles/3He_kaon_simc2.root";
  string root_name  ="../rootfiles/3He_kaon_simc2.root";
  string root_name2 ="../rootfiles/3He_kaon_theory.root";
  
  TFile* ifr = new TFile(root_name.c_str());
  TFile* ifr2 = new TFile(root_name2.c_str());

  TTree* T = (TTree* )ifr ->Get("SNT");
  TTree* T2 = (TTree* )ifr2 ->Get("SNT");


  double mm_min = -100.;
  double mm_max =  400;
  int    mm_bin =  500;
  TH1D* hmm =new TH1D("hmm","",mm_bin,mm_min,mm_max);
  TH1D* hmm2 =new TH1D("hmm2","",mm_bin,mm_min,mm_max);
  hmm->SetLineColor(2);
  hmm2->SetLineColor(4);
  double M3HL = 2.99199;
  double Mth = M3HL;

  float mm,Weight,Normfac;
  T->SetBranchAddress("mmnuc",&mm);
  T->SetBranchAddress("Weight",&Weight);
  T->SetBranchAddress("Normfac",&Normfac);

  int ENum = T->GetEntries();
  cout<<"ENum : "<<ENum<<endl;
  double mass=0.0;
  for(int i=0;i<ENum;i++){

    Weight=0.0;
    Normfac=0.0;
    mm =0.0;
    mass =0.0;
    T->GetEntry(i);

    hmm->Fill((mm-Mth)*1000.,1./Weight/Normfac);
    
  }



  float mm2,Weight2,Normfac2;
  T2->SetBranchAddress("mmnuc",&mm2);
  T2->SetBranchAddress("Weight",&Weight2);
  T2->SetBranchAddress("Normfac",&Normfac2);

  int ENum2 = T2->GetEntries();
  cout<<"ENum2 : "<<ENum2<<endl;

  for(int i=0;i<ENum2;i++){

    Weight2=0.0;
    Normfac2=0.0;
    mm2 =0.0;

    T2->GetEntry(i);
    hmm2->Fill((mm2-Mth)*1000.,1./Weight2/Normfac2);

  }



  TH1D* hR = new TH1D("hR","",mm_bin,mm_min,mm_max);
  double x,y,y2, ratio;
  for(int i=0;i<mm_bin;i++){

    x  = hmm  -> GetBinCenter(i);
    y  = hmm  -> GetBinContent(i);
    y2 = hmm2 -> GetBinContent(i);

    
    ratio = (y-y2)/sqrt(y2);
  
    if(y2!=0)  hR->Fill(x,ratio);

  }
  

  TCanvas* c0 = new TCanvas("c0","c0");
  TCanvas* c1 = new TCanvas("c1","c1");

  c0->cd();
  hmm->Draw();
  hmm2->Draw("same");
  c1->cd();
  hR->Draw();
  
}