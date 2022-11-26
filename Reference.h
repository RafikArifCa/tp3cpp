/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   reference.h
 * Author: etudiant
 *
 * Created on 21 octobre 2022, 22:08
 */

#ifndef REFERENCE_H
#define REFERENCE_H
#include <string>
#include "ContratException.h"

namespace biblio
{

  class Reference
  {
  public:
    Reference (
               const std::string &p_auteurs,
               const std::string &p_titre,
               int p_annee,
               const std::string &p_identifiant);

    virtual
    ~Reference () { };

    void asgAnnee (int p_annee);

    int reqAnnee () const;
    const std::string &reqAuteurs () const;
    const std::string &reqIdentifiant () const;
    const std::string &reqTitre () const;

    virtual const std::string reqReferenceFormate () const;
    virtual Reference* clone ()const;

    bool operator== (const Reference &p_reference) const;

  private:
    std::string m_auteurs;
    std::string m_titre;
    int m_annee;
    std::string m_identifiant;
  };
} // fin namespace biblio

#endif /* REFERENCE_H */
