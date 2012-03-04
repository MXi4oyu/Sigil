/************************************************************************
**
**  Copyright (C) 2011  John Schember <john@nachtimwald.com>
**
**  This file is part of Sigil.
**
**  Sigil is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  Sigil is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with Sigil.  If not, see <http://www.gnu.org/licenses/>.
**
*************************************************************************/

#include <QtCore/QCoreApplication>

#include "Misc/SettingsStore.h"
#include "sigil_constants.h"

static QString SETTINGS_GROUP = "user_preferences";
static QString KEY_DEFAULT_METADATA_LANGUAGE = "default_metadata_lang";
static QString KEY_SPLIT_VIEW_ORIENTATION = "split_view_orientation";
static QString KEY_SPLIT_VIEW_ORDER = "split_view_order";
static QString KEY_ZOOM_IMAGE = "zoom_image";
static QString KEY_ZOOM_TEXT = "zoom_text";
static QString KEY_ZOOM_WEB = "zoom_web";
static QString KEY_DICTIONARY_NAME = "dictionary_name";
static QString KEY_RENAME_TEMPLATE = "rename_template";

SettingsStore::SettingsStore()
#ifndef Q_WS_MAC
    : QSettings(QSettings::IniFormat, QSettings::UserScope, QCoreApplication::organizationName(), QCoreApplication::applicationName())
#endif
{
}

QString SettingsStore::defaultMetadataLang()
{
    clearSettingsGroup();
    return value(SETTINGS_GROUP + "/" + KEY_DEFAULT_METADATA_LANGUAGE, "English").toString();
}

Qt::Orientation SettingsStore::splitViewOrientation()
{
    clearSettingsGroup();
    return static_cast<Qt::Orientation>(value(SETTINGS_GROUP + "/" + KEY_SPLIT_VIEW_ORIENTATION, Qt::Vertical).toInt());;
}

bool SettingsStore::splitViewOrder()
{
    clearSettingsGroup();
    return static_cast<bool>(value(SETTINGS_GROUP + "/" + KEY_SPLIT_VIEW_ORDER, true).toBool());
}

float SettingsStore::zoomImage()
{
    clearSettingsGroup();
    return value(SETTINGS_GROUP + "/" + KEY_ZOOM_IMAGE, ZOOM_NORMAL).toFloat();;
}

float SettingsStore::zoomText()
{
    clearSettingsGroup();
    return value(SETTINGS_GROUP + "/" + KEY_ZOOM_TEXT, ZOOM_NORMAL).toFloat();
}

float SettingsStore::zoomWeb()
{
    clearSettingsGroup();
    return value(SETTINGS_GROUP + "/" + KEY_ZOOM_WEB, ZOOM_NORMAL).toFloat();
}

QString SettingsStore::dictionary()
{
    clearSettingsGroup();
    return value(SETTINGS_GROUP + "/" + KEY_DICTIONARY_NAME, "en_US").toString();
}

QString SettingsStore::renameTemplate()
{
    clearSettingsGroup();
    return value(SETTINGS_GROUP + "/" + KEY_RENAME_TEMPLATE, "Section001").toString();
}

void SettingsStore::setDefaultMetadataLang(const QString &lang)
{
    clearSettingsGroup();
    setValue(SETTINGS_GROUP + "/" + KEY_DEFAULT_METADATA_LANGUAGE, lang);
}

void SettingsStore::setSplitViewOrientation(Qt::Orientation orientation)
{
    clearSettingsGroup();
    setValue(SETTINGS_GROUP + "/" + KEY_SPLIT_VIEW_ORIENTATION, orientation);
}

void SettingsStore::setSplitViewOrder(bool order )
{
    clearSettingsGroup();
    setValue(SETTINGS_GROUP + "/" + KEY_SPLIT_VIEW_ORDER, order);
}


void SettingsStore::setZoomImage(float zoom)
{
    clearSettingsGroup();
    setValue(SETTINGS_GROUP + "/" + KEY_ZOOM_IMAGE, zoom);
}

void SettingsStore::setZoomText(float zoom)
{
    clearSettingsGroup();
    setValue(SETTINGS_GROUP + "/" + KEY_ZOOM_TEXT, zoom);
}

void SettingsStore::setZoomWeb(float zoom)
{
    clearSettingsGroup();
    setValue(SETTINGS_GROUP + "/" + KEY_ZOOM_WEB, zoom);
}

void SettingsStore::setDictionary(const QString &name)
{
    clearSettingsGroup();
    setValue(SETTINGS_GROUP + "/" + KEY_DICTIONARY_NAME, name);
}

void SettingsStore::setRenameTemplate(const QString &name)
{
    clearSettingsGroup();
    setValue(SETTINGS_GROUP + "/" + KEY_RENAME_TEMPLATE, name);
}

void SettingsStore::clearSettingsGroup()
{
    while (!group().isEmpty()) {
        endGroup();
    }
}
