/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Ouvrage.h"
#include "ContratException.h"
#include <string>
#include <sstream>
#include "Reference.h"
#include "validationFormat.h"


using namespace std;
namespace biblio
{


  Ouvrage::Ouvrage (const string&p_auteurs, const string&p_titre,
                    const int&p_annee, const string&p_identifiant,
                    const string&p_editeur, const string&p_ville)

  : Reference (p_auteurs, p_titre, p_annee, p_identifiant), m_editeur (p_editeur), m_ville (p_ville)
  {
    PRECONDITION (p_editeur.length () > 0);
    PRECONDITION (util::validerFormatNom (p_editeur));
    PRECONDITION (p_ville.length () > 0);
    PRECONDITION (util::validerFormatNom (p_ville));
    PRECONDITION (util::validerCodeIssn (p_identifiant));

    POSTCONDITION (m_editeur == p_editeur);
    POSTCONDITION (m_ville == p_ville);

    INVARIANTS ();
  }


  const string&
  Ouvrage::reqVille ()const
  {
    return m_ville;
  }


  const string&
  Ouvrage::reqEditeur () const
  {
    return m_editeur;

  }


  const std::string
  Ouvrage::reqReferenceFormate ()const
  {
    ostringstream os;

    os << Reference::reqReferenceFormate () << "." << Reference::reqAnnee () << "." <<  Reference::reqIdentifiant ();
    return os.str ();

  }


  Reference*
  Ouvrage::clone ()const
  {

    return new Ouvrage (*this);
  }


  void
  Ouvrage::verifieInvariant () const { }




} // Fin namespace biblio


