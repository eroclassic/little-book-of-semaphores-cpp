#pragma once

#include <string>
#include <vector>

// Run two threads that record A1, A2 and B1, B2 while satisfying the
// rendezvous ordering constraints described in README.md.
std::vector<std::string> run_rendezvous();
