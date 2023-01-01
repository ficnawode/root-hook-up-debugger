void tof()
{
    AnalysisTree::Chain* treeIn = new AnalysisTree::Chain(
        std::vector<std::string>({"filelist.txt"}), std::vector<std::string>({"rTree"}));

    auto* eve_header = new AnalysisTree::EventHeader();
    auto* rec_header = new AnalysisTree::EventHeader();
    auto* sim_tracks = new AnalysisTree::Particles();
    auto* vtx_tracks = new AnalysisTree::TrackDetector();
    auto* sim_vtx_matching = new AnalysisTree::Matching();
    auto* tof_hits = new AnalysisTree::HitDetector();

    AnalysisTree::Configuration* config = treeIn->GetConfiguration();
    const int mass2 = config->GetBranchConfig("TofHits").GetFieldId("mass2");
    const int qp_tof = config->GetBranchConfig("TofHits").GetFieldId("qp_tof");

    treeIn->SetBranchAddress("SimEventHeader.", &eve_header);
    treeIn->SetBranchAddress("SimParticles.", &sim_tracks);
    treeIn->SetBranchAddress("VtxTracks.", &vtx_tracks);
    treeIn->SetBranchAddress("RecEventHeader.", &rec_header);
    treeIn->SetBranchAddress("TofHits.", &tof_hits);
    treeIn->SetBranchAddress("VtxTracks2SimParticles.", &sim_vtx_matching);

    int N = 0;
    const int Nevents = treeIn->GetEntries();

    TFile* fileOut1 = TFile::Open("../out/tof.root", "recreate");
    TH2F hc_qp_mass2(
        "hc_qp_mass2",
        "correlation qp_tof mass2; sign(q)*p (GeV/c);mass^2 (GeV)^2",
        1000,
        -6,
        6,
        1000,
        -1,
        4); // simulated

    for(int i = 0; i < Nevents; i++)
    {
        treeIn->GetEntry(i);

        for(const auto& tof_hit: *tof_hits)
        {
            const float tof_mass2 = tof_hit.GetField<float>(mass2);
            const float tof_qp_tof = tof_hit.GetField<float>(qp_tof);
            hc_qp_mass2.Fill(tof_qp_tof, tof_mass2);
        }
    }

    hc_qp_mass2.Write();
    fileOut1->Close();
}
