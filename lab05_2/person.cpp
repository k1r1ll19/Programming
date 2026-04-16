#include "person.h"
#include "passform_ru.h"
#include "passform_en.h"

bool RuP::Craft(QWidget* parent) {
    PassFormRu form(this, parent);
    form.exec();
    return form.printed;
}

bool AmP::Craft(QWidget* parent) {
    PassFormEn form(this, parent);
    form.exec();
    return form.printed;
}
