#pragma once
#include <exception>
#include "CMDefines.h"

#ifdef CM_HAS_EXCEPTION
#include <QString>

BEGIN_CM_NAMESPACE

class CM_Base_Exception{
public:
    virtual QString what() const  {
        return QString("Exception Name:")
            .append(this->getExceptionName());
    }
    virtual const QString getExceptionName()const { 
        return QStringLiteral
        ("Unknown Exception!Must override function to get correct exception name."); 
    }
};

class Mem_Not_Found_Exception : public CM_Base_Exception {
public:
    Mem_Not_Found_Exception():
        Mem_Not_Found_Exception(QStringLiteral("Unknown Member!"))
    {}

    Mem_Not_Found_Exception(const QString& memberName) : 
        memberName(memberName)
    {}

     QString what() const override {
        return CM_Base_Exception::what()
            .append(',')
            .append('\n')
            .append(QStringLiteral("Member Name:"))
            .append(memberName);
    }

     const QString getExceptionName()const override{ 
        return QStringLiteral("Mem_Not_Found_Exception"); 
    }

    const QString& getMemberName() { return memberName; }

private:
    const QString memberName;
};

class Dynamic_Invoke_Failed_Exception : public CM_Base_Exception {
public:
    Dynamic_Invoke_Failed_Exception():
        Dynamic_Invoke_Failed_Exception(QStringLiteral("Unknown Function!"))
    {}

    Dynamic_Invoke_Failed_Exception(const QString& functionName)
        : functionName(functionName) 
    {}

     QString what() const override {
        return CM_Base_Exception::what()
            .append(',')
            .append('\n')
            .append(QStringLiteral("Function Name:"))
            .append(functionName);
    }

     const QString getExceptionName()const override{ 
        return QStringLiteral("Dynamic_Invoke_Failed_Exception"); 
    }

private:
    QString functionName;
};

class Clone_Failed_Exception : public CM_Base_Exception {
public:
    Clone_Failed_Exception():
        Clone_Failed_Exception(
            QStringLiteral("Unknown destination className"),
            QStringLiteral("Unknown original className"))
    {}
    Clone_Failed_Exception(const QString& desClassName):
        Clone_Failed_Exception(
            desClassName,
            QStringLiteral("Unknown original ClassName"))
    {}

    Clone_Failed_Exception(const QString& desClassName,const QString& originalClassName)
        : desClassName(desClassName), originalClassName(originalClassName) 
    {}

     QString what() const override {
        return CM_Base_Exception::what()
            .append(',')
            .append('\n')
            .append(QStringLiteral("Destination ClassName:"))
            .append(desClassName)
            .append(',')
            .append('\n')
            .append(QStringLiteral("Original ClassName:"))
            .append(originalClassName);
    }

     const QString getExceptionName()const override{ 
        return QStringLiteral("Clone_Failed_Exception"); 
    }

private:
    QString desClassName;
    QString originalClassName;
};

class Runtime_Error_Exception :public CM_Base_Exception { 
public:
    Runtime_Error_Exception()
      : Runtime_Error_Exception(QStringLiteral("Unknown Reason"),
    {}

  const QString getExceptionName() const override {
    return QStringLiteral("Runtime_Error_Exception");
  }
    QString what() const override {
        return CM_Base_Exception::what()
            .append(',')
            .append('\n')
            .append(ERROR Reason : )
            .append(reason);
    }
private:
    QString reason;
};



#endif // 0

END_CM_NAMESPACE
