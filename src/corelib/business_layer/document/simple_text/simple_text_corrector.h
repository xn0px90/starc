#pragma once

#include <business_layer/document/text/abstract_text_corrector.h>


namespace BusinessLayer {

/**
 * @brief Класс корректирующий текст аудиопостановки
 */
class CORE_LIBRARY_EXPORT SimpleTextCorrector : public AbstractTextCorrector
{
    Q_OBJECT

public:
    explicit SimpleTextCorrector(QTextDocument* _document);
    ~SimpleTextCorrector() override;

    /**
     * @brief Установить необходимость корректировать текст блоков имён персонажей
     */
    void setCorrectionOptions(const QStringList& _options) override;

protected:
    /**
     * @brief Очистить все сохранённые параметры
     */
    void clearImpl() override;

    /**
     * @brief Выполнить корректировки
     */
    void makeCorrections(int _position = -1, int _charsChanged = 0) override;

    /**
     * @brief Выполнить "мягкие" корректировки
     */
    void makeSoftCorrections(int _position = -1, int _charsChanged = 0) override;

private:
    class Implementation;
    QScopedPointer<Implementation> d;
};

} // namespace BusinessLayer
