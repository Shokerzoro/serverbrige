#ifndef UNITER_MESSAGING_SPECIALIZEDMESSAGES_H
#define UNITER_MESSAGING_SPECIALIZEDMESSAGES_H

#include "eventmessage.h"
#include "querymessage.h"

#include <contract/common/resourceabstract.h>

#include <filesystem>
#include <memory>
#include <string>

namespace messaging {

enum class TransactionAction {
    COMMIT,
    ROLLBACK
};

class CrudEventMessage : public EventMessage {
public:
    static std::shared_ptr<CrudEventMessage> create(
        contract::CrudAction action,
        std::shared_ptr<contract::ResourceAbstract> resource);

private:
    explicit CrudEventMessage(std::shared_ptr<contract::UniterMessage> message);
};

class CrudQueryMessage : public QueryMessage {
public:
    static std::shared_ptr<CrudQueryMessage> create(
        contract::CrudAction action,
        std::shared_ptr<contract::ResourceAbstract> resource);

private:
    explicit CrudQueryMessage(std::shared_ptr<contract::UniterMessage> message);
};

class TransactionQueryMessage : public QueryMessage {
public:
    static std::shared_ptr<TransactionQueryMessage> createBegin(const std::string& transactionId);
    static std::shared_ptr<TransactionQueryMessage> createFinish(
        const std::string& transactionId,
        TransactionAction action);

private:
    explicit TransactionQueryMessage(std::shared_ptr<contract::UniterMessage> message);
};

class PresignedUrlQueryMessage : public QueryMessage {
public:
    static std::shared_ptr<PresignedUrlQueryMessage> create(const std::string& object);

private:
    explicit PresignedUrlQueryMessage(std::shared_ptr<contract::UniterMessage> message);
};

class DownloadFileQueryMessage : public QueryMessage {
public:
    static std::shared_ptr<DownloadFileQueryMessage> create(
        const std::string& object,
        const std::string& presignedUrl);

private:
    explicit DownloadFileQueryMessage(std::shared_ptr<contract::UniterMessage> message);
};

class UploadFileQueryMessage : public QueryMessage {
public:
    static std::shared_ptr<UploadFileQueryMessage> create(
        const std::string& object,
        const std::string& presignedUrl,
        const std::filesystem::path& localPath);

private:
    explicit UploadFileQueryMessage(std::shared_ptr<contract::UniterMessage> message);
};

} // namespace messaging

#endif // UNITER_MESSAGING_SPECIALIZEDMESSAGES_H
