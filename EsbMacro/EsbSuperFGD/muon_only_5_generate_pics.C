/*

  Macro that shows how to run the WC digitization on an existing simulation
  (e.g., produced with ess_sim.C).

  Based on the example in the presentation from
  Konstantin Gertsenberger
  
  .L ess_dig_gen_pics.C
  ess_dig_gen_pics()
  
*/

void muon_only_5_generate_pics(TString inFile = "fgd_dig_mu_only.root", 
	      TString parFile = "params_mu_only.root",
	      TString outFile = "fgd_dig_gen_pics.root",
              Int_t nStartEvent = 0, Int_t nEvents = 25)
{
  using namespace esbroot;

  FairRunAna *fRun= new FairRunAna();
  // Set Input Source and Output file
  FairFileSource *fFileSource = new FairFileSource(inFile);
  fRun->SetSource(fFileSource);
 
  fRun->SetSink(new FairRootFileSink(outFile));

  // -----  Parameter database   --------------------------------------------
  FairRuntimeDb* rtdb = fRun->GetRuntimeDb();

  FairParRootFileIo* parIo1 = new FairParRootFileIo();
  parIo1->open(parFile);
  rtdb->setFirstInput(parIo1);
  
  rtdb->setOutput(parIo1); 
  rtdb->saveOutput();

  // Set Tasks for Reconstruction
  FairTask* digitizer = new digitizer::superfgd::FgdMppcDisplay("Granular Task","../../EsbGeometry/EsbSuperFGD/EsbConfig/fgdconfig",0,0,0);
  fRun->AddTask(digitizer);   
  fRun->Init(); // initializing
  fRun->Run(nStartEvent, nStartEvent + nEvents);
}
