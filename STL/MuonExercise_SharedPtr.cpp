//
//  MuonExercise_SharedPtr.cpp
//  STL
//
//  Created by Manuel Giffels on 08.06.15.
//  Copyright (c) 2015 Manuel Giffels. All rights reserved.
//
#include <algorithm>
#include <iostream>
#include <memory>
#include <random>

class Muon {
public:
    Muon(double pt,
         double eta,
         double phi):m_pt(pt),
    m_eta(eta),
    m_phi(phi){}
    void print() const {
        std::cout << "Muon pt: " << m_pt
        << " eta: " << m_eta
        << " phi: " << m_phi << std::endl;
    }
    const double pt() const{
        return m_pt;
    }
    const double eta() const{
        return m_eta;
    }
    const double phi() const{
        return m_phi;
    }
    
private:
    double m_pt;
    double m_eta;
    double m_phi;
};

class MuonProducer {
public:
    MuonProducer(double min_pt, double max_pt,
                 double min_eta, double max_eta,
                 double min_phi, double max_phi):
    m_pt_distribution(min_pt, max_pt),
    m_eta_distribution(min_eta, max_eta),
    m_phi_distribution(min_phi, max_phi) {}

    std::shared_ptr<Muon> produce() {
        return std::make_shared<Muon>(random_pt(), random_eta(), random_phi());
    }
private:
    const double random_pt() {
        return m_pt_distribution(m_generator);
    }
    const double random_eta() {
        return m_eta_distribution(m_generator);
    }
    const double random_phi() {
        return m_phi_distribution(m_generator);
    }
    
    std::uniform_real_distribution<double> m_pt_distribution;
    std::uniform_real_distribution<double> m_eta_distribution;
    std::uniform_real_distribution<double> m_phi_distribution;
    std::mt19937_64 m_generator;
};

int main(int argc, char* argv[]) {
    const double pi(std::atan(1)*4);
    
    MuonProducer my_muon_producer(1., 1000., -2.5, 2.5, 0., 2*pi);
    
    std::vector<std::shared_ptr<Muon> > my_muons;
    my_muons.reserve(100);
    
    for(unsigned int i=0; i<100; ++i) {
        my_muons.push_back(my_muon_producer.produce());
    }
    
    std::sort(my_muons.begin(), my_muons.end(), [](const std::shared_ptr<Muon> a, const std::shared_ptr<Muon> b){return a->pt() < b->pt();});
    
    for (const auto it: my_muons) {
        it->print();
    }

    const double pt_cut(500.);
    
    unsigned int n_muons_above_pt_cut = count_if(my_muons.begin(), my_muons.end(), [&pt_cut](const std::shared_ptr<Muon> a){return a->pt() > pt_cut;});
    std::cout << n_muons_above_pt_cut << " muons have a p_T larger than " << pt_cut << " GeV!" << std::endl;
    
    std::cout << "The muon having the min p_T is " << std::endl;
    my_muons[0]->print();
    
    std::cout << "The muon having the max p_T is " << std::endl;
    my_muons[my_muons.size()-1]->print();
    
    return 0;
}
