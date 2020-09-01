#include "tableheader.h"

TableHeader::TableHeader(QWidget *parent): QWidget(parent){
    layout = new QHBoxLayout(this);
    this->setLayout(layout);
    layout->setMargin( 0 );
    layout->setSpacing(0);
    layout->setAlignment(Qt::AlignLeft);
    setMinimumHeight(60);
    this->setStyleSheet(R"(
        border: 1px solid #CFD8DC;
        color: black;
        border-width: 1px 0;
        background-color: #EEEEEE;
        margin:0px;
        padding:10px;)"
    );
}

void TableHeader::addField(const QString &new_field){
    auto pos = std::find_if(fields.begin(), fields.end(), [&](auto &el){
        return el->text() == new_field;
    });
    if( pos == fields.end()){
        auto new_label = new QLabel(new_field);
        new_label->setFixedWidth(170);
        new_label->setStyleSheet("border-right: 1px solid #BDBDBD;") ;
        new_label->setAlignment(Qt::AlignCenter);
        new_label->setWordWrap(true);
        fields.push_back(new_label);
        layout->addWidget(new_label);
    }
}

void TableHeader::setVisibility(const QString &field, bool visibility){
    QString s;
    auto pos = std::find_if(fields.begin(), fields.end(), [&](auto &el){
        return el->text().trimmed().toLower() == field.trimmed().toLower();
    });
    if(pos != fields.end()) visibility ? (*pos)->show() : (*pos)->hide();
}

void TableHeader::showAll(){
    std::for_each(fields.begin(), fields.end(), [](auto& el){
        el->show();
    });
}

void TableHeader::hideAll(){
    std::for_each(fields.begin(), fields.end(), [](auto& el){
        el->hide();
    });
}

std::vector<QString> TableHeader::getFields() const{
    std::vector<QString> v;
    std::transform(fields.begin(), fields.end(), std::back_inserter(v), [](QLabel* l){ return l->text();});
    return v;
}

void TableHeader::resetFields(){
    fields.clear();
}

