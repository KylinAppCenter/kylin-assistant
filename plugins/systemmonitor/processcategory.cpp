/*
 * Copyright (C) 2013 ~ 2018 National University of Defense Technology(NUDT) & Tianjin Kylin Ltd.
 *
 * Authors:
 *  Kobe Lee    xiangli@ubuntukylin.com/kobe24_lixiang@126.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "processcategory.h"
#include "../widgets/myimagebutton.h"

ProcessCategory::ProcessCategory(int tabIndex, QWidget *parent)
    : QWidget(parent)
    ,width(16)
    ,height(16)
    ,activeIndex(tabIndex)
{
    setFixedSize(width * 3, height);

    layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    activeProcessButton = new MyImageButton(this);
    activeProcessButton->setCheckable(true);
    activeProcessButton->setObjectName("ActiveProcessBtn");

    userProcessButton = new MyImageButton(this);
    userProcessButton->setCheckable(true);
    userProcessButton->setObjectName("UserProcessBtn");

    allProcessButton = new MyImageButton(this);
    allProcessButton->setCheckable(true);
    allProcessButton->setObjectName("AllProcessBtn");

    if (activeIndex == 0) {
        activeProcessButton->setChecked(true);
        userProcessButton->setChecked(false);
        allProcessButton->setChecked(false);
    }
    else if (activeIndex == 2) {
        activeProcessButton->setChecked(false);
        userProcessButton->setChecked(false);
        allProcessButton->setChecked(true);
    }
    else {
        activeProcessButton->setChecked(false);
        userProcessButton->setChecked(true);
        allProcessButton->setChecked(false);
    }

    connect(activeProcessButton, &MyImageButton::clicked, this, [=] {
        activeIndex = 0;
        emit this->activeWhoseProcessList(activeIndex);
        activeProcessButton->setChecked(true);
        userProcessButton->setChecked(false);
        allProcessButton->setChecked(false);
    });
    connect(userProcessButton, &MyImageButton::clicked, this, [=] {
        activeIndex = 1;
        emit this->activeWhoseProcessList(activeIndex);
        activeProcessButton->setChecked(false);
        userProcessButton->setChecked(true);
        allProcessButton->setChecked(false);
    });
    connect(allProcessButton, &MyImageButton::clicked, this, [=] {
        activeIndex = 2;
        emit this->activeWhoseProcessList(activeIndex);
        activeProcessButton->setChecked(false);
        userProcessButton->setChecked(false);
        allProcessButton->setChecked(true);
    });

    layout->addWidget(activeProcessButton);
    layout->addWidget(userProcessButton);
    layout->addWidget(allProcessButton);
    this->setLayout(layout);
}

ProcessCategory::~ProcessCategory()
{
    delete activeProcessButton;
    delete userProcessButton;
    delete allProcessButton;
    delete layout;
}
