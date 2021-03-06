#ifndef IENUMERABLE_H_
# define IENUMERABLE_H_

namespace linq
{
    template <typename Handle>
    class TEnumerable : private Handle
    {
        typedef typename Handle::iterator iterator_type;
        typedef decltype(*std::declval<iterator_type>()) out_t;

    public:
        TEnumerable() = delete;
        ~TEnumerable() = default;
        TEnumerable(TEnumerable const &rhs)
                : Handle(static_cast<Handle const &>(rhs))
        {}
        TEnumerable(Handle const &rhs)
                : Handle(rhs)
        {}

        constexpr const iterator_type &begin() const noexcept(true) {
            return static_cast<Handle const &>(*this).begin();
        }
        constexpr const iterator_type &end() const noexcept(true) {
            return static_cast<Handle const &>(*this).end();
        }

        constexpr out_t First() const noexcept(true) {
            return static_cast<Handle const &>(*this).first();
        }
        constexpr auto FirstOrDefault() const noexcept(true) {
            return static_cast<Handle const &>(*this).firstOrDefault();
        }

        constexpr out_t Last() const noexcept(true) {
            return static_cast<Handle const &>(*this).last();
        }
        constexpr auto LastOrDefault() const noexcept(true) {
            return static_cast<Handle const &>(*this).lastOrDefault();
        }

        constexpr auto Reverse() const noexcept(true) {
            using ret_t = TEnumerable<decltype(static_cast<Handle const &>(*this).reverse())>;
            return ret_t(static_cast<Handle const &>(*this).reverse());
        }
        template<typename Func>
        constexpr auto Select(Func const &nextloader_) const noexcept(true) {
            using ret_t = TEnumerable<decltype(static_cast<Handle const &>(*this).select(nextloader_))>;
            return ret_t(static_cast<Handle const &>(*this).select(nextloader_));
        }
        template<typename... Funcs>
        constexpr auto SelectMany(Funcs const &...keys) const noexcept(true) {
            using ret_t = TEnumerable<decltype(static_cast<Handle const &>(*this).selectMany(keys...))>;
            return ret_t(static_cast<Handle const &>(*this).selectMany(keys...));
        }

        template<typename Func>
        constexpr auto Where(Func const &nextfilter_) const noexcept(true) {
            using ret_t = TEnumerable<decltype(static_cast<Handle const &>(*this).where(nextfilter_))>;
            return ret_t(static_cast<Handle const &>(*this).where(nextfilter_));
        }
        template<typename... Funcs>

        constexpr auto GroupBy(Funcs const &...keys) const noexcept(true) {
            using ret_t = TEnumerable<decltype(static_cast<Handle const &>(*this).groupBy(keys...))>;
            return ret_t(static_cast<Handle const &>(*this).groupBy(keys...));
        }
        template<typename... Funcs>

        constexpr auto OrderBy(Funcs const &...keys) const noexcept(true) {
            using ret_t = TEnumerable<decltype(static_cast<Handle const &>(*this).orderBy(keys...))>;
            return ret_t(static_cast<Handle const &>(*this).orderBy(keys...));
        }
        constexpr auto Asc() const noexcept(true) {
            using ret_t = TEnumerable<decltype(static_cast<Handle const &>(*this).asc())>;
            return ret_t(static_cast<Handle const &>(*this).asc());
        }
        constexpr auto Desc() const noexcept(true) {
            using ret_t = TEnumerable<decltype(static_cast<Handle const &>(*this).desc())>;
            return ret_t(static_cast<Handle const &>(*this).desc());
        }

        constexpr auto Skip(std::size_t const offset) const noexcept(true) {
            using ret_t = TEnumerable<decltype(static_cast<Handle const &>(*this).skip(offset))>;
            return ret_t(static_cast<Handle const &>(*this).skip(offset));
        }
        template<typename Func>
        constexpr auto SkipWhile(Func const &func) const noexcept(true) {
            using ret_t = TEnumerable<decltype(static_cast<Handle const &>(*this).skip_while(func))>;
            return ret_t(static_cast<Handle const &>(*this).skip_while(func));
        }

        constexpr auto Take(int const limit) const noexcept(true) {
            using ret_t = TEnumerable<decltype(static_cast<Handle const &>(*this).take(limit))>;
            return ret_t(static_cast<Handle const &>(*this).take(limit));
        }
        template<typename Func>
        constexpr auto TakeWhile(Func const &func) const noexcept(true) {
            using ret_t = TEnumerable<decltype(static_cast<Handle const &>(*this).take_while(func))>;
            return ret_t(static_cast<Handle const &>(*this).take_while(func));
        }

        template<typename Func>
        constexpr auto &Each(Func const &pred) const noexcept(true) {
            static_cast<Handle const &>(*this).each(pred);
            return *this;
        }

        template<typename T>
        constexpr bool Contains(T const &elem) const noexcept(true) {
            return static_cast<Handle const &>(*this).contains(elem);
        }
        constexpr bool Any() const noexcept(true) {
            return static_cast<Handle const &>(*this).any();
        }
        constexpr auto Count() const noexcept(true) {
            return static_cast<Handle const &>(*this).count();
        }

        constexpr auto All() const noexcept(true) {
            using ret_t = TEnumerable<decltype(static_cast<Handle const &>(*this).all())>;
            return ret_t(static_cast<Handle const &>(*this).all());
        }
        constexpr auto Min() const noexcept(true) {
            return static_cast<Handle const &>(*this).min();
        }
        constexpr auto Max() const noexcept(true) {
            return static_cast<Handle const &>(*this).max();
        }
        constexpr auto Sum() const noexcept(true) {
            return static_cast<Handle const &>(*this).sum();
        }

        template<typename Key>
        constexpr auto &operator[](Key const &key) const {
            return static_cast<Handle const &>(*this).operator[](key);
        }

    };
}

#endif // !IENUMERABLE_H_
