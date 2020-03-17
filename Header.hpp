#pragma once
#include <iostream>
#include<string>

using namespace std;



const string graph_def_filename = "frozen_graph.pb";

// Setup global state for TensorFlow.
tensorflow::port::InitMain(argv[0], &argc, &argv);

// Load a frozen model
tensorflow::GraphDef graph_def;
TF_CHECK_OK(tensorflow::ReadBinaryProto(tensorflow::Env::Default(),
    graph_def_filename, &graph_def));