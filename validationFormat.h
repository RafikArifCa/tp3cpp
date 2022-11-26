/**
 * \file validationFormat.h
 * \brief
 * \author Thierry Eude
 * \version 0.1
 * \date 2016-02-01
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_
#include <string>
#include "ContratException.h"

namespace util
{
  bool validerFormatNom (const std::string &p_nom);
  bool validerCodeIssn (const std::string &p_issn);
  bool validerCodeIsbn (const std::string &p_isbn);
  //  bool isValidISBN (const std::string &p_isbn);
  //  bool isValidISSN (const std::string &p_issn);
  bool validerAnnee (const std::string &annee);
} // namespace util
#endif /* VALIDATIONFORMAT_H_ */
