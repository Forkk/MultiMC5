/* Copyright 2014 MultiMC Contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <QWidget>

#include "logic/BaseInstance.h"
#include "logic/net/NetJob.h"
#include "logic/MinecraftProcess.h"
#include "BasePage.h"

class EnabledItemFilter;
class MinecraftProcess;
namespace Ui
{
class LogPage;
}

class LogPage : public QWidget, public BasePage
{
	Q_OBJECT

public:
	explicit LogPage(MinecraftProcess *proc, QWidget *parent = 0);
	virtual ~LogPage();
	virtual QString displayName() const override
	{
		return tr("Minecraft Log");
	}
	virtual QIcon icon() const override
	{
		return QIcon::fromTheme("log");
	}
	virtual QString id() const override
	{
		return "console";
	}
	virtual bool apply();
	virtual QString helpPage() const override
	{
		return "Minecraft-Log";
	}
	virtual bool shouldDisplay() const;

private:
	/**
	 * @brief write a colored paragraph
	 * @param data the string
	 * @param color the css color name
	 * this will only insert a single paragraph.
	 * \n are ignored. a real \n is always appended.
	 */
	void writeColor(QString text, const char *color, const char *background);

private slots:
	/**
	 * @brief write a string
	 * @param data the string
	 * @param mode the WriteMode
	 * lines have to be put through this as a whole!
	 */
	void write(QString data, MessageLevel::Enum level = MessageLevel::MultiMC);
	void on_btnPaste_clicked();
	void on_btnCopy_clicked();
	void on_btnClear_clicked();

private:
	Ui::LogPage *ui;
	MinecraftProcess *m_process;
	int m_last_scroll_value = 0;
	bool m_scroll_active = true;
	int m_saved_offset = 0;
};
