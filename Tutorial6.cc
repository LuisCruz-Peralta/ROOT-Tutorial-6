void Tutorial6(){

  TH1F *hist= new TH1F("hist","Histogram",100,0,10);
  
  TRandom2 *rand = new TRandom2(3);
  
  fstream file;
  file.open("data.txt",ios::out); //Introducimos numeros aleatorios al .txt
  
  for (int i =0; i<1000; i++){
  
     double r = rand->Gaus(5,1); //Datos con distribucion gaussiana y dando los parametros mu y sigma 
     file << r << endl;
  }
  file.close();
  file.open("data.txt",ios::in);
  
  double value;
  
  while(1) //leer cada uno de los datos del .txt en un ciclo while
  {
      file >> value;
      hist->Fill(value);
      if(file.eof()) break ;
  };
  file.close();
  hist->GetXaxis()->SetTitle("Distribution");
  hist->GetYaxis()->SetTitle("Entries");
  
  TCanvas *c1 = new TCanvas();
  hist->Draw();
}
