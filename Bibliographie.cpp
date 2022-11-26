/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Bibliographie.h"
#include "Reference.h"
#include "ContratException.h"
#include <string>
#include <sstream>



using namespace std;

namespace biblio
{


  Bibliographie::Bibliographie (const string& p_nomBibliographie)
  : m_nomBibliographie (p_nomBibliographie)
  {
    //PRECONDITION (!p_nomBibliographie.empty ()­);
    POSTCONDITION (m_nomBibliographie == p_nomBibliographie);
    //POSTCONDITION (m_vReferences.empty ());

    INVARIANTS ();
  }


  Bibliographie::Bibliographie (const Bibliographie &p_bibliographie)
  {
    m_nomBibliographie = p_bibliographie.m_nomBibliographie;
    copierVector (p_bibliographie);

    POSTCONDITION (m_nomBibliographie == p_bibliographie.m_nomBibliographie);
    POSTCONDITION (m_vReferences.empty ());

    INVARIANTS ();
  }


  Bibliographie::~Bibliographie () { } //destructeur de la classe bibliographie


  const string
  Bibliographie::reqBibliographieFormate () const
  {
    ostringstream os;
    os << m_nomBibliographie << endl << "---" << endl;
    for (int i = 0; i < m_vReferences.size (); i++)
      {
        os << "[" << i + 1 << "]" << m_vReferences[i]-> reqReferenceFormate () << endl;
      }
    return os.str ();
  }


  void
  Bibliographie::ajouterReference (const Reference & p_nouvelleReference)
  {
    if (!referenceEstDejaPresente (p_nouvelleReference.reqIdentifiant ()))
      {
        m_vReferences.push_back (p_nouvelleReference.clone ()); //??????
      }
    INVARIANTS ();
  }


  /*bool
  Bibliographie::referenceEstDejaPresente (const std::string&p_identifiant) const
  {
    bool estPresente = false;
    for (int i = 0; i < m_vReferences.size (); i++)
      {
        if (m_vReferences[i] > Reference::reqIdentifiant (­) == p_identifiant)
          {
            estPresente = true;
          }
      }
    return estPresente;

  }*/


  void
  Bibliographie::copierVector (const Bibliographie & p_bibliographie)
  {
    PRECONDITION (m_vReferences.empty ());

    for (int i = 0; i < p_bibliographie.m_vReferences.size (); i++)
      {
        ajouterReference (*p_bibliographie.m_vReferences[i]);
      }
    INVARIANTS ();
  }


  void
  Bibliographie::viderVector ()
  {
    for (int i = 0; i < m_vReferences.size (); i++)
      {
        delete m_vReferences[i];
      }
    m_vReferences.clear ();
    INVARIANTS ();
  }


  void
  Bibliographie::verifieInvariant ()const
  {
    INVARIANT (m_vReferences.size () >= 0);
  }

}//FIN DU NAMESPACE BIBLIO
