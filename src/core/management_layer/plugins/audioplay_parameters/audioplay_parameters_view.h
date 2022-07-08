#pragma once

#include <interfaces/ui/i_document_view.h>
#include <ui/widgets/widget/widget.h>


namespace Ui {

/**
 * @brief Представление параметров аудиопостановки
 */
class AudioplayParametersView : public Widget, public IDocumentView
{
    Q_OBJECT

public:
    explicit AudioplayParametersView(QWidget* _parent = nullptr);
    ~AudioplayParametersView() override;

    /**
     * @brief Реализация интерфейса IDocumentView
     */
    /** @{ */
    QWidget* asQWidget() override;
    void setEditingMode(ManagementLayer::DocumentEditingMode _mode) override;
    /** @} */

    void setHeader(const QString& _header);
    Q_SIGNAL void headerChanged(const QString& _header);

    void setPrintHeaderOnTitlePage(bool _print);
    Q_SIGNAL void printHeaderOnTitlePageChanged(bool _print);

    void setFooter(const QString& _footer);
    Q_SIGNAL void footerChanged(const QString& _footer);

    void setPrintFooterOnTitlePage(bool _print);
    Q_SIGNAL void printFooterOnTitlePageChanged(bool _print);

    void setOverrideCommonSettings(bool _override);
    Q_SIGNAL void overrideCommonSettingsChanged(bool _override);

    void setAudioplayTemplate(const QString& _templateId);
    Q_SIGNAL void audioplayTemplateChanged(const QString& _templateId);

    void setShowBlockNumbers(bool _show);
    Q_SIGNAL void showBlockNumbersChanged(bool _show);

    void setContinueBlockNumbers(bool _continue);
    Q_SIGNAL void continueBlockNumbersChanged(bool _continue);

protected:
    /**
     * @brief Обновить переводы
     */
    void updateTranslations() override;

    /**
     * @brief Обновляем виджет при изменении дизайн системы
     */
    void designSystemChangeEvent(DesignSystemChangeEvent* _event) override;

private:
    class Implementation;
    QScopedPointer<Implementation> d;
};

} // namespace Ui
