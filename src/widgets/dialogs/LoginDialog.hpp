#pragma once

#include "widgets/BaseWidget.hpp"

#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QtCore/QVariant>

namespace chatterino
{
    class BasicLoginWidget : public QWidget
    {
    public:
        BasicLoginWidget();

        struct
        {
            QVBoxLayout layout;
            QHBoxLayout horizontalLayout;
            QPushButton loginButton;
            QPushButton pasteCodeButton;
        } ui_;
    };

    class AdvancedLoginWidget : public QWidget
    {
    public:
        AdvancedLoginWidget();

        void refreshButtons();

        struct
        {
            QVBoxLayout layout;

            QLabel instructionsLabel;

            QFormLayout formLayout;

            QLineEdit userIDInput;
            QLineEdit usernameInput;
            QLineEdit clientIDInput;
            QLineEdit oauthTokenInput;

            struct
            {
                QHBoxLayout layout;

                QPushButton addUserButton;
                QPushButton clearFieldsButton;
            } buttonUpperRow;

            struct
            {
                QHBoxLayout layout;

                QPushButton fillInUserIDButton;
            } buttonLowerRow;
        } ui_;
    };

    class LoginWidget : public QDialog
    {
    public:
        LoginWidget();

    private:
        struct
        {
            QVBoxLayout mainLayout;

            QTabWidget tabWidget;

            QDialogButtonBox buttonBox;

            BasicLoginWidget basic;

            AdvancedLoginWidget advanced;
        } ui_;
    };

}  // namespace chatterino
