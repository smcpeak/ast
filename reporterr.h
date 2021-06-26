// reporterr.h            see license.txt for copyright and terms of use
// interface for reporting errors and warnings

#ifndef REPORTERR_H
#define REPORTERR_H

#include "str.h"        // rostring

class ReportError {
public:
  virtual ~ReportError() {}
  // report an error; 'str' should not have a newline
  virtual void reportError(rostring str)=0;

  // report a warning
  virtual void reportWarning(rostring str)=0;
};


// throw away messages, but count them
class SilentReportError : public ReportError {
public:
  int errors;
  int warnings;

public:
  virtual ~SilentReportError() {}
  SilentReportError();
  void reportError(rostring str) override;
  void reportWarning(rostring str) override;
};

extern SilentReportError silentReportError;


// print messages to stdout with "error: " or "warning: " prepended
class SimpleReportError : public SilentReportError {
public:
  virtual ~SimpleReportError() {}
  void reportError(rostring str) override;
  void reportWarning(rostring str) override;
};

extern SimpleReportError simpleReportError;


#endif // REPORTERR_H
